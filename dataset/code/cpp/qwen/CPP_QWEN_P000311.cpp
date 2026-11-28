#include <iostream>
#include <string>
using namespace std;

int main() {
    string num1, num2;
    cin >> num1 >> num2;
    string res = "";
    int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        carry = sum / 10;
        res = char('0' + sum % 10) + res;
    }
    cout << res << endl;
    return 0;
}
