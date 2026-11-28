#include <iostream>
#include <string>
using namespace std;

void generateBinaryStringsNoConsecutiveOnes(int n, string current) {
    if (n == 0) {
        cout << current << endl;
        return;
    }
    generateBinaryStringsNoConsecutiveOnes(n - 1, current + "0");
    if (current.empty() || current.back() != '1') {
        generateBinaryStringsNoConsecutiveOnes(n - 1, current + "1");
    }
}

int main() {
    int N;
    cin >> N;
    generateBinaryStringsNoConsecutiveOnes(N, "");
    return 0;
}
