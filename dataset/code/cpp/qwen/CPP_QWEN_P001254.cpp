#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    sort(nums.begin(), nums.end(), [](const string& a, const string& b) {
        return a + b > b + a;
    });
    
    string result = "";
    for (string& s : nums) result += s;
    
    // Handle leading zeros
    if (result[0] == '0') cout << "0" << endl;
    else cout << result << endl;
    
    return 0;
}
