#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long N;
    cin >> N;
    vector<int> freq(10, 0);
    if (N == 0) freq[0] = 1;
    while (N > 0) {
        freq[N % 10]++;
        N /= 10;
    }
    for (int i = 0; i < 10; ++i) {
        if (i > 0) cout << " ";
        cout << freq[i];
    }
    cout << endl;
    return 0;
}
