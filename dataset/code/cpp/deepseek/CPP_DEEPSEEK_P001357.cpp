Here is the C++ code:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isAdditive(string num) {
    int n = num.size();
    if (n < 3) return false;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            string a = num.substr(0, i + 1), b = num.substr(i + 1, j - i);
            if (a.size() > 1 && a[0] == '0' || b.size() > 1 && b[0] == '0') continue;
            if (a.size() > 0 && a.size() < b.size() && b.size() > 1 && b.substr(b.size() - 1) == a && a + a == num) return true;
            if (b.size() > 0 && b.size() < a.size() && a.size() > 1 && a.substr(a.size() - 1) == b && a + b == num) return true;
        }
    return false;
}

int main() {
    string num;
    cin >> num;
    if(isAdditive(num))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
This code first checks if the string can be split into additive sequences. For every possible split, it checks if the string formed by the first two numbers is a valid additive number.