#include <iostream>
#include <string>
using namespace std;

void generateBinaryStrings(int n, string current) {
    if (n == 0) {
        cout << current << endl;
        return;
    }
    generateBinaryStrings(n - 1, current + "0");
    generateBinaryStrings(n - 1, current + "1");
}

int main() {
    int n;
    cin >> n;
    generateBinaryStrings(n, "");
    return 0;
}
