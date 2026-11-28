#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    long long ways[N+1];
    ways[0] = 1;
    ways[1] = 1;

    for(int i = 2; i <= N; i++) {
        ways[i] = 0;
        for(int j = 0; j < i; j++) {
            ways[i] += ways[j] * ways[i-j-1];
        }
    }

    cout << ways[N] << endl;

    return 0;
}