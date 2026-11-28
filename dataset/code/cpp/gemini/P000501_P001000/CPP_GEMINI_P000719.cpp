#include <iostream>
#include <string>
#include <vector>
void restore_ip(const std::string& s, int idx, std::vector<std::string>& parts) {
    if (parts.size() == 4) {
        if (idx == (int)s.length()) {
            std::cout << parts[0] << "." << parts[1] << "." << parts[2] << "." << parts[3] << std::endl;
        }
        return;
    }
    for (int l = 1; l <= 3 && idx + l <= (int)s.length(); l++) {
        std::string part = s.substr(idx, l);
        if ((part[0] == '0' && part.length() > 1) || std::stoi(part) > 255) continue;
        parts.push_back(part);
        restore_ip(s, idx + l, parts);
        parts.pop_back();
    }
}
int main() {
    std::string s;
    if (std::cin >> s) {
        std::vector<std::string> parts;
        restore_ip(s, 0, parts);
    }
    return 0;
}