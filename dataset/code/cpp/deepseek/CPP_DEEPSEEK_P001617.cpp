#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int prefix_sum = 0;
    int count = 0;
    for(int i=0; i<n; i++) {
        prefix_sum += arr[i];
        if(prefix_sum % 2 == 0) {
            count++;
        }
    }

    cout << count << "\n";
    return 0;
}