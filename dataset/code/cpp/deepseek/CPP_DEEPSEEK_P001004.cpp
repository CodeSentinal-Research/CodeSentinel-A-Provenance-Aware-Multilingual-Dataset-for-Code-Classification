#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int height = 0;
    while (N > 0) {
        N /= 2;
        height++;
    }

    cout << height;

    return 0;
}