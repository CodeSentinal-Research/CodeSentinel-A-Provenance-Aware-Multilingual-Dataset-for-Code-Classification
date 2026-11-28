#include <iostream>
using namespace std;

int kthGrammar(int N, int K) {
    if (N == 1) return 0;
    int parent = kthGrammar(N - 1, (K + 1) / 2);
    if (K % 2 == 1) return parent;
    else return 1 - parent;
}

int main() {
    int N, K;
    cin >> N >> K;
    cout << kthGrammar(N, K) << endl;
    return 0;
}
