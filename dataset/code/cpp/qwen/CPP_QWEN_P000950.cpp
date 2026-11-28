#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> phi(N + 1);
    for (int i = 0; i <= N; ++i) phi[i] = i;
    
    for (int i = 2; i <= N; ++i) {
        if (phi[i] == i) {
            for (int j = i; j <= N; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
    
    for (int i = 1; i <= N; ++i) {
        if (i > 1) cout << " ";
        cout << phi[i];
    }
    cout << endl;
    return 0;
}
