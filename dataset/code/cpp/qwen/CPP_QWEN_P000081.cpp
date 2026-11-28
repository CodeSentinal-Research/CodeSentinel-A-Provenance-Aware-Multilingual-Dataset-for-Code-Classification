#include <iostream>
using namespace std;

int main() {
    char c;
    cin >> c;
    cout << (isdigit(c) ? "Digit" : "Not Digit") << endl;
    return 0;
}
