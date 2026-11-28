#include <iostream>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    
    int arr1[M], arr2[N];
    for (int i = 0; i < M; i++) {
        cin >> arr1[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> arr2[i];
    }
    
    int merged[M + N];
    int i = 0, j = 0, k = 0;
    while (i < M && j < N) {
        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }
    while (i < M) {
        merged[k++] = arr1[i++];
    }
    while (j < N) {
        merged[k++] = arr2[j++];
    }
    
    for (int i = 0; i < M + N; i++) {
        cout << merged[i] << " ";
    }
    cout << endl;
    
    return 0;
}