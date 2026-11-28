#include <iostream>
using namespace std;

int main() {
    int M, N, K;
    cin >> M >> N >> K;
    
    int* A = new int[M];
    int* B = new int[N];
    
    for(int i=0; i<M; i++) {
        cin >> A[i];
    }
    
    for(int i=0; i<N; i++) {
        cin >> B[i];
    }
    
    while(K>0 && M>0 && N>0) {
        if(A[0] < B[0]) {
            swap(A[0], B[0]);
            K -= 1;
        } else {
            K -= 1;
        }
        M -= 1;
        N -= 1;
    }
    
    cout << A[0] << endl;
    
    delete[] A;
    delete[] B;

    return 0;
}