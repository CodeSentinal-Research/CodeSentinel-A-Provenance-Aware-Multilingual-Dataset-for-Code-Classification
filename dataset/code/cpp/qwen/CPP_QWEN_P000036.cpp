#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string bin = "";
    if (n == 0) bin = "0";
    while (n > 0) {
        bin = char('0' + n % 2) + bin;
        n /= 2;
    }
    cout << bin << endl;
    return 0;
}
