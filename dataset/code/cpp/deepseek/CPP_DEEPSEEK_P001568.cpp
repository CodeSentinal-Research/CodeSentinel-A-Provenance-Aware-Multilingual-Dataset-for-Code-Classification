#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> nums(N);
    for(int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int maxLen = 0;
    for(int i = 0; i < N; i++) {
        int len = 1;
        for(int j = i+1; j < N; j++) {
            if(nums[i] == nums[j]) {
                len++;
            } else {
                break;
            }
        }
        maxLen = max(maxLen, len);
    }

    cout << maxLen << endl;
    
    return 0;
}