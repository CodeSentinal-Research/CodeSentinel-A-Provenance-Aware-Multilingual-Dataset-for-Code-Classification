#include <iostream>
#include <string>
void gen_no_cons_ones(int n, std::string cur) {
    if ((int)cur.length() == n) {
        std::cout << cur << std::endl;
        return;
    }
    gen_no_cons_ones(n, cur + "0");
    if (cur.empty() || cur.back() != '1') {
        gen_no_cons_ones(n, cur + "1");
    }
}
int main() {
    int n;
    if (std::cin >> n) {
        gen_no_cons_ones(n, "");
    }
    return 0;
}