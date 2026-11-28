#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> trib(N + 1, 0);
    if (N >= 1) trib[1] = 1;
    if (N >= 2) trib[2] = 1;
    for (int i = 3; i <= N; ++i) {
        trib[i] = trib[i-1] + trib[i-2] + trib[i-3];
    }
    cout << trib[N] << endl;
    return 0;
}
