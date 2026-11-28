#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generateSequence(int N) {
    vector<int> seq(2*N - 1);
    for(int i = 1; i <= N; i++) {
        seq[i-1] = seq[N+i-2] = i;
    }

    for(int i = N; i > 0; i--) {
        seq[2*i - 1] = seq[2*i - 2] = i;
    }

    sort(seq.begin(), seq.end());

    for(int i = 0; i < 2*N - 1; i++) {
        cout << seq[i] << " ";
    }
}

int main() {
    int N;
    cin >> N;
    generateSequence(N);
    return 0;
}