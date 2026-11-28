#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int arr[N];
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    int prefixSum[N];
    prefixSum[0] = arr[0];
    for(int i = 1; i < N; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
    
    for(int i = 0; i < N; i++) {
        if(i > 0) {
            cout << " ";
        }
        cout << prefixSum[i];
    }
    cout << endl;
    
    return 0;
}