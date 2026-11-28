#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long X;
    int N;
    cin >> X >> N;
    vector<long long> rem(N), mod(N);
    for (int i = 0; i < N; ++i) cin >> rem[i] >> mod[i];
    
    bool valid = true;
    for (int i = 0; i < N; ++i) {
        if (X % mod[i] != rem[i]) {
            valid = false;
            break;
        }
    }
    cout << (valid ? "true" : "false") << endl;
    return 0;
}
