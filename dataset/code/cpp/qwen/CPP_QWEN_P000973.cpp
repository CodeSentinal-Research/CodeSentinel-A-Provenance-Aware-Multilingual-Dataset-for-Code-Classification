#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int S;
    cin >> S;
    int count = 0;
    for (int i = 1; i <= 6; ++i) {
        for (int j = 1; j <= 6; ++j) {
            if (i + j == S) count++;
        }
    }
    cout << fixed << setprecision(6) << (double)count / 36.0 << endl;
    return 0;
}
