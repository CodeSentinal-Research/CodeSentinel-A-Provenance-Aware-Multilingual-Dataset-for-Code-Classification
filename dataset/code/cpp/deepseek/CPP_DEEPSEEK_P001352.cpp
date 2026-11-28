#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str;
    cin >> str;
    int n = str.length();

    int prev = str[0] - '0';
    for(int i = 1; i < n; i++) {
        int curr = str[i] - '0';
        if(curr < prev) {
            cout << "NO" << endl;
            return 0;
        }
        prev = curr;
    }

    cout << "YES" << endl;
    return 0;
}