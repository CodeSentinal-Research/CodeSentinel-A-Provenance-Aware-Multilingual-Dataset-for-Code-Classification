#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int arr[N];
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int result = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            int diff = arr[j] - arr[i];
            for(int k = j+1; k < N; k++) {
                if((arr[k] - arr[j]) == diff) {
                    result++;
                }
            }
        }
    }

    cout << result << endl;
    return 0;
}