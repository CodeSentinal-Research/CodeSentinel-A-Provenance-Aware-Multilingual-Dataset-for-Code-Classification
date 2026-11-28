#include <iostream>
using namespace std;

int main() {
    int days;
    cin >> days;
    cout << days / 365 << " " << (days % 365) / 7 << " " << days % 7 << endl;
    return 0;
}
