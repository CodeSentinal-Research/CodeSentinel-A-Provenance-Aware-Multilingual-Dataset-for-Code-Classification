#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    
    string res = "";
    int i = a.length() - 1, j = b.length() - 1, carry = 0;
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        carry = sum / 2;
        res += char('0' + sum % 2);
    }
    
    reverse(res.begin(), res.end());
    cout << res << endl;
    return 0;
}
