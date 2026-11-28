#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int arr[N];
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    int max_index = 0;
    for(int i = 1; i < N; i++) {
        if(arr[i] > arr[max_index]) {
            max_index = i;
        }
    }
    
    cout << max_index;
    
    return 0;
}