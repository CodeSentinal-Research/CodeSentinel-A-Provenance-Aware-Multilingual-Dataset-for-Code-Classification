#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
    std::string findSet(std::unordered_map<std::string, std::string>& parent, const std::string& s) {
        if (parent[s] == s) return s;
        return parent[s] = findSet(parent, parent[s]);
    }
public:
    std::vector<std::vector<std::string>> accountsMerge(std::vector<std::vector<std::string>>& accounts) {
        std::unordered_map<std::string, std::string> parent;
        std::unordered_map<std::string, std::string> emailToName;

        for (const auto& acc : accounts) {
            const std::string& name = acc[0];
            const std::string& first = acc[1];
            for (size_t i = 1; i < acc.size(); i++) {
                const std::string& email = acc[i];
                if (!parent.count(email)) parent[email] = email;
                emailToName[email] = name;
                std::string r1 = findSet(parent, first);
                std::string r2 = findSet(parent, email);
                if (r1 != r2) parent[r1] = r2;
            }
        }

        std::unordered_map<std::string, std::vector<std::string>> unions;
        for (const auto& [email, _] : parent) {
            unions[findSet(parent, email)].push_back(email);
        }

        std::vector<std::vector<std::string>> res;
        for (auto& [root, emails] : unions) {
            std::sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), emailToName[root]);
            res.push_back(emails);
        }
        return res;
    }
};