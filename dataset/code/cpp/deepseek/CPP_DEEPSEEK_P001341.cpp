#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

void generateTimes(int n) {
    for (int h = 0; h < 12; h++) {
        for (int m = 0; m < 60; m++) {
            if (bitset<10>(h << 6 | m).count() == n) {
                cout << "Hour: " << h << ", Minute: " << m << endl;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    generateTimes(n);
    return 0;
}