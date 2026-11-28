#include <iostream>
using namespace std;

int main() {
    long long x, y;
    cin >> x >> y;
    
    int steps = 0;
    while (y > x) {
        if (y % 2 == 0) {
            y /= 2;
        } else {
            y++;
        }
        steps++;
    }
    
    steps += x - y;
    
    cout << steps << endl;
    return 0;
}
