#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> nums(N);
    for(int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    
    int count = 0;
    for(int i = 0; i < N; i++) {
        int product = 1;
        for(int j = i; j < N; j++) {
            product *= nums[j];
            if(product < K) {
                count++;
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}