#include <iostream>
using namespace std;

int main() {
    char c;
    cin >> c;
    bool isSpecial = !isalnum(c) && !isspace(c);
    cout << (isSpecial ? "Special Symbol" : "Not Special Symbol") << endl;
    return 0;
}
