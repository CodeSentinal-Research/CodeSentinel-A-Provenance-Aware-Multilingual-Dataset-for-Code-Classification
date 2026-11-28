#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool isValidSerialization(string preorder) {
    istringstream iss(preorder);
    string token;
    int slots = 1;
    while (iss >> token) {
        if (slots == 0) return false;
        slots--;
        if (token != "#") slots += 2;
    }
    return slots == 0;
}

int main() {
    string s;
    getline(cin, s);
    cout << (isValidSerialization(s) ? "YES" : "NO") << endl;
    return 0;
}
