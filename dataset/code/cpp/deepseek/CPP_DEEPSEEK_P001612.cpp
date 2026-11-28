#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    int sum = 0;

    for(int i=0; i<N; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    if(sum % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }

    sum /= 3;

    int count = 0, curr_sum = 0;

    for(int i=0; i<N; i++) {
        curr_sum += arr[i];

        if(curr_sum == sum) {
            if(curr_sum == sum) {
                count++;
            } else {
                count = 1;
            }
        }
    }

    cout << count << endl;

    return 0;
}