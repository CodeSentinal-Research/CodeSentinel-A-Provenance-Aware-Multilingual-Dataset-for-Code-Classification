#include <iostream>
using namespace std;

int main() {
    int y;
    cin >> y;
    bool leap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    cout << (leap ? "Leap Year" : "Not a Leap Year") << endl;
    return 0;
}
