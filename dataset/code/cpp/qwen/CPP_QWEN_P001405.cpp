#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int reverseDigits(int x) {
    int rev = 0;
    while (x > 0) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    return rev;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    unordered_map<int, int> freq;
    long long count = 0;
    
    for (int num : nums) {
        int key = num - reverseDigits(num);
        count += freq[key];
        freq[key]++;
    }
    
    cout << count << endl;
    return 0;
}
