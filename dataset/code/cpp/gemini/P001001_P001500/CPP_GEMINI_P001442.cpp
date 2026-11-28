#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<std::string>> findDuplicate(std::vector<std::string>& paths) {
        std::unordered_map<std::string, std::vector<std::string>> map;

        for (const auto& p : paths) {
            std::istringstream iss(p);
            std::string dirPath, fileInfo;
            iss >> dirPath;
            while (iss >> fileInfo) {
                size_t open = fileInfo.find('(');
                std::string fileName = fileInfo.substr(0, open);
                std::string content = fileInfo.substr(open + 1, fileInfo.length() - open - 2);
                map[content].push_back(dirPath + "/" + fileName);
            }
        }

        std::vector<std::vector<std::string>> res;
        for (auto& [_, files] : map) {
            if (files.size() > 1) res.push_back(std::move(files));
        }
        return res;
    }
};