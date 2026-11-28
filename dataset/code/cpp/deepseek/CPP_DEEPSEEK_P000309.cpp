#include <iostream>
#include <string>
using namespace std;

string multiply(string num1, string num2) {
    int n1 = num1.length();
    int n2 = num2.length();
    int len = n1 + n2;
    int *res = new int[len];
    for (int i = 0; i < len; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            mul += res[i + j + 1];
            res[i + j + 1] = mul % 10;
            mul /= 10;
            res[i + j] += mul;
        }
    }

    string product = "";
    if (res[0] != 0) {
        product += to_string(res[0]);
    }
    for (int i = 1; i <= len; i++) {
        product += to_string(res[i]);
    }
    delete[] res;
    reverse(product.begin(), product.end());
    return product;
}

int main() {
    string num1, num2;
    cin >> num1 >> num2;
    cout << multiply(num1, num2);
    return 0;
}