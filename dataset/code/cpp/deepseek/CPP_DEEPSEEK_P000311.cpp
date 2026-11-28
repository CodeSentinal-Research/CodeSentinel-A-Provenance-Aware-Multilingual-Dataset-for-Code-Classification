#include <iostream>
#include <string>

using namespace std;

string addStrings(string num1, string num2) {
    if (num1.empty())
        return num2;
    if (num2.empty())
        return num1;

    string res;
    int n1 = num1.size() - 1, n2 = num2.size() - 1, carry = 0;
    while (n1 >= 0 || n2 >= 0) {
        int sum = carry;
        if (n1 >= 0)
            sum += num1[n1--] - '0';
        if (n2 >= 0)
            sum += num2[n2--] - '0';
        carry = sum / 10;
        res.push_back(sum % 10 + '0');
    }
    if (carry != 0)
        res.push_back(carry + '0');
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string num1, num2;
    cin >> num1 >> num2;
    cout << addStrings(num1, num2);
    return 0;
}