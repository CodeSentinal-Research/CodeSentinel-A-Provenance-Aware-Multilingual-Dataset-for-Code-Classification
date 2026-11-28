#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int charToVal(char c) {
    if (isdigit(c)) return c - '0';
    return c - 'A' + 10;
}

char valToChar(int v) {
    if (v < 10) return '0' + v;
    return 'A' + v - 10;
}

int main() {
    string num;
    int A, B;
    cin >> num >> A >> B;
    
    // Convert to decimal
    long long dec = 0;
    for (char c : num) {
        dec = dec * A + charToVal(c);
    }
    
    // Convert to base B
    if (dec == 0) { cout << "0" << endl; return 0; }
    
    string res = "";
    while (dec > 0) {
        res += valToChar(dec % B);
        dec /= B;
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
    return 0;
}
