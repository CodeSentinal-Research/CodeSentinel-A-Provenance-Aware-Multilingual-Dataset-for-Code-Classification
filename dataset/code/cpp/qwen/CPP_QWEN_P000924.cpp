#include <iostream>
#include <string>
using namespace std;

int main() {
    long long N;
    cin >> N;
    if (N == 0) { cout << "0" << endl; return 0; }
    string bin = "";
    while (N > 0) {
        bin = char('0' + N % 2) + bin;
        N /= 2;
    }
    cout << bin << endl;
    return 0;
}
