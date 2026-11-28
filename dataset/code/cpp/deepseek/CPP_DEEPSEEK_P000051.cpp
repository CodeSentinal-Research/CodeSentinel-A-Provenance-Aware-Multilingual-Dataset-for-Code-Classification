#include <iostream>

using namespace std;

int main() {
    char c;
    cout << "Enter a character: ";
    cin >> c;

    if(c >= 'A' && c <= 'Z') {
        cout << "Uppercase";
    } else if(c >= 'a' && c <= 'z') {
        cout << "Lowercase";
    } else {
        cout << "Not a letter";
    }

    return 0;
}