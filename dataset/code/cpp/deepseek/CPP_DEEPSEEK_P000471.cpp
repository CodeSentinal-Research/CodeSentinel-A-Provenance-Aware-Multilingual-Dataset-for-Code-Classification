#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<int> counts(N, 0);
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            if(arr[i] > arr[j]) {
                counts[i]++;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        cout << counts[i] << " ";
    }
    cout << endl;

    return 0;
}
This code first reads the number of elements `N` and then the elements themselves. It then creates a vector `counts` of size `N`, all initialized to `0`. For each element in the input array, it increments the corresponding count in the `counts` array for all larger elements. Finally, it prints the `counts` array.