#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
int main() {
    int size, q;
    if (std::cin >> size >> q) {
        std::queue<int> window;
        double sum = 0;
        std::cout << std::fixed << std::setprecision(5);
        while (q--) {
            int val;
            std::cin >> val;
            window.push(val);
            sum += val;
            if ((int)window.size() > size) {
                sum -= window.front();
                window.pop();
            }
            std::cout << (sum / window.size()) << std::endl;
        }
    }
    return 0;
}