#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::string> files(n);
        for (int i = 0; i < n; i++) std::cin >> files[i];
        std::string ext;
        std::cin >> ext;
        if (ext[0] != '.') ext = "." + ext;
        for (const auto& f : files) {
            if (f.length() >= ext.length() && f.rfind(ext) == f.length() - ext.length()) {
                std::cout << f << "\n";
            }
        }
    }
    return 0;
}