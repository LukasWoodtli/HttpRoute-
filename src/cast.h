#include <sstream>
#include <string>
#include <map>
#include <memory>

struct castable;
using castableSharedPtr = std::shared_ptr<castable>;


struct castable {
public:
	virtual ~castable() {}
	virtual bool isCastable(const std::string& text) = 0;

	template<class T>
	static void registerType(const std::string& typeName);
	static bool isTypeCastable(const std::string& typeName, const std::string& value) {
		const auto it = s_map.find(typeName);
		if (it == s_map.end()) {
			return false;
		}
		return it->second->isCastable(value);
	}

private:
	static std::map<std::string, castableSharedPtr> s_map;
};

std::map<std::string, castableSharedPtr> castable::s_map;

template<typename T>
struct type_castable : castable {

	bool isCastable(const std::string& text) override {
		T var;
		std::istringstream istream;
		istream.str(text);
		istream >> var;
		return not istream.fail();
	}
};



template <class T>
void castable::registerType(const std::string& typeName) {
		s_map.insert(std::pair<std::string, castableSharedPtr>(typeName, std::make_shared<type_castable<T>>()));
	}


#define REGISTER_CASTABLE_TYPE(T) do {castable::registerType<T>(#T); } while (0)
