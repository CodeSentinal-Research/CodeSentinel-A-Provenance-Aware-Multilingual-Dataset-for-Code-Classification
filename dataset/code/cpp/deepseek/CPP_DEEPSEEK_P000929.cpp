#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int** A = new int*[N];
    for(int i=0; i<N; i++) {
        A[i] = new int[M];
        for(int j=0; j<M; j++) {
            cin >> A[i][j];
        }
    }

    int** B = new int*[N];
    for(int i=0; i<N; i++) {
        B[i] = new int[M];
        for(int j=0; j<M; j++) {
            cin >> B[i][j];
        }
    }

    int** sum = new int*[N];
    for(int i=0; i<N; i++) {
        sum[i] = new int[M];
        for(int j=0; j<M; j++) {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cout << sum[i][j] << " ";
        }
        cout << "\n";
    }

    for(int i=0; i<N; i++) {
        delete [] A[i];
    }
    delete [] A;
    
    for(int i=0; i<N; i++) {
        delete [] B[i];
    }
    delete [] B;
    
    for(int i=0; i<N; i++) {
        delete [] sum[i];
    }
    delete [] sum;

    return 0;
}