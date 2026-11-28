#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> catalan(N + 1, 0);
    catalan[0] = 1;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < i; ++j) {
            catalan[i] += catalan[j] * catalan[i-j-1];
        }
    }
    cout << catalan[N] << endl;
    return 0;
}
