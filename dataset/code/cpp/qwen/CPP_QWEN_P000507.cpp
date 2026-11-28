#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool solve(string preorder) {
    stringstream ss(preorder);
    string node;
    int slots = 1;
    while (getline(ss, node, ',')) {
        if (slots == 0) return false;
        slots--;
        if (node != "#") slots += 2;
    }
    return slots == 0;
}

int main() {
    string s; getline(cin, s);
    cout << (solve(s) ? "true" : "false") << endl;
    return 0;
}
