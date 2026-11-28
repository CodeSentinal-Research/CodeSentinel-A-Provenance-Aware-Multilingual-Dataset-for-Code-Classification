#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int n1 = a.length();
    int n2 = b.length();
    int len = max(n1, n2);
    int carry = 0;
    string result = "";

    while(len--) {
        int sum = carry;
        if (n1-- > 0) sum += a[n1] - '0';
        if (n2-- > 0) sum += b[n2] - '0';

        result += to_string(sum%2);
        carry = sum / 2;
    }

    if (carry) result += to_string(carry);
    reverse(result.begin(), result.end());

    cout << result;
    return 0;
}