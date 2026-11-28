#include <iostream>
using namespace std;

int main() {
    int N, x, y;
    cin >> N >> x >> y;
    if ((x + y) % 2 == 0) {
        cout << "First";
    } else {
        cout << "Second";
    }
    return 0;
}