#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string num1, num2;
    cin >> num1 >> num2;
    if (num1 == "0" || num2 == "0") {
        cout << "0" << endl;
        return 0;
    }
    vector<int> res(num1.size() + num2.size(), 0);
    for (int i = num1.size() - 1; i >= 0; i--) {
        for (int j = num2.size() - 1; j >= 0; j--) {
            int mul = (a[i] - '0') * (b[j] - '0');
            int p1 = i + j, p2 = i + j + 1;
            int sum = mul + res[p2];
            res[p2] = sum % 10;
            res[p1] += sum / 10;
        }
    }
    string res_str = "";
    for (int num : res) if (!(res_str.empty() && num == 0)) res_str += to_string(num);
    cout << res_str << endl;
    return 0;
}
