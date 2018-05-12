#include <string>
#include <vector>
#include <sstream>
#include <utility>


class Endpoint {
public:
    Endpoint(const std::string& target) {
        std::string path;
        std::tie(path, m_fragment) = splitFragment(target);
        m_sections = splitSections(path);
        
    }

    const std::vector<std::string> & sections() const {
        return m_sections;
    }

    const std::string & fragment() const {
        return m_fragment;
    }
private:
    
    static std::pair<std::string, std::string> splitFragment(const std::string& target) {
        const constexpr char DELIMITER = '#';
        auto index = target.find(DELIMITER);
        if (index != std::string::npos) {
            return std::make_pair(target.substr(0, index), target.substr(index + 1, target.length()));
        }

        return std::make_pair(target, "");
    }
        
    static std::vector<std::string> splitSections(const std::string& path) {
        const constexpr char DELIMITER = '/';
        std::vector<std::string> sections;
        std::string section;
        std::string tempPath((path));

        if (path.find(DELIMITER) == 0) {
            tempPath.replace(0, 1, "");
        }
        std::istringstream sectionsStream(tempPath);
        while (std::getline(sectionsStream, section, DELIMITER)) {
            sections.push_back(section);
        }
        return sections;
    }
  
    std::vector<std::string> m_sections;
    std::string m_fragment;

};
