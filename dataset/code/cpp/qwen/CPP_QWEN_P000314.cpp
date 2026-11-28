#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string res = "";
    while (n > 0) {
        n--;
        res = char('A' + n % 26) + res;
        n /= 26;
    }
    cout << res << endl;
    return 0;
}
