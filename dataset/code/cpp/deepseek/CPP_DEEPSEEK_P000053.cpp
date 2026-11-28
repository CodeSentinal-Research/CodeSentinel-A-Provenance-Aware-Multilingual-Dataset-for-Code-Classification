#include <iostream>
using namespace std;

int main() {
    char c;
    cout << "Enter a lowercase character: ";
    cin >> c;

    if(c >= 'a' && c <= 'z') {
        c = c - 'a' + 'A';
    }

    cout << "Uppercase equivalent: " << c << endl;

    return 0;
}