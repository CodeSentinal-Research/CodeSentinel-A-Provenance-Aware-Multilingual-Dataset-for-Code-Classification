#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string removeKdigits(string num, int k) {
    while (k > 0) {
        int n = num.length();
        for (int i = 0; i < n - 1; i++) {
            if (num[i] > num[i + 1]) {
                num.erase(num.begin() + i);
                k--;
                break;
            }
        }
        if (num == "0") return "0";
        if (k == 0) break;
    }
    return num;
}

int main() {
    string num;
    int k;
    cin >> num >> k;
    num = removeKdigits(num, k);
    cout << num;
    return 0;
}