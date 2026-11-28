#include <iostream>
#include <string>
void gen_par(int n, int o, int c, std::string cur) {
    if ((int)cur.length() == 2 * n) {
        std::cout << cur << std::endl;
        return;
    }
    if (o < n) gen_par(n, o + 1, c, cur + "(");
    if (c < o) gen_par(n, o, c + 1, cur + ")");
}
int main() {
    int n;
    if (std::cin >> n) {
        gen_par(n, 0, 0, "");
    }
    return 0;
}