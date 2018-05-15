#include <sstream>

struct castable {
protected:
	const std::string m_typeText;
	castable(const std::string& typeText) : m_typeText(typeText) {}
public:
	virtual bool cast(const std::string& text) = 0;
	const std::string getTypeText() const {return m_typeText;}
};

template<typename T>
struct type_castable : castable {
	type_castable(const std::string &typeString) : castable(typeString) {}

	bool cast(const std::string& text) override {
		T var;
		std::istringstream istream;
		istream.str(text);
		istream >> var;
		return not istream.fail();
	}
};

#define MAKE_TYPE_CASTABLE(T) std::unique_ptr<castable>(new type_castable<T>(#T))
//std::vector<std::unique_ptr<castable>>;
