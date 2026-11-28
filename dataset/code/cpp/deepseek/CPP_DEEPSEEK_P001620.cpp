#include <iostream>
using namespace std;

int main() {
    int N, Q, A, sum = 0;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        if(i%2 == 0)
            sum += A[i];
    }
    cin >> Q;
    while(Q--) {
        cin >> A >> A >> A;
        cout << sum << endl;
    }
    return 0;
}