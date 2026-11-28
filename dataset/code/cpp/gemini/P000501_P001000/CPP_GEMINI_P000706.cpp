#include <iostream>
#include <string>
void gen_bin(int n, std::string cur) {
    if ((int)cur.length() == n) {
        std::cout << cur << std::endl;
        return;
    }
    gen_bin(n, cur + "0");
    gen_bin(n, cur + "1");
}
int main() {
    int n;
    if (std::cin >> n) {
        gen_bin(n, "");
    }
    return 0;
}