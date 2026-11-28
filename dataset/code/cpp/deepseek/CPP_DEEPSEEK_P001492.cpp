#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findKClosest(vector<int> &arr, int n, int k, int x) {
    vector<int> result;
    
    auto lower = lower_bound(arr.begin(), arr.end(), x);
    auto upper = upper_bound(arr.begin(), arr.end(), x);
    
    if(lower - arr.begin() > k)
        upper--;
    
    if(n - upper > k)
        lower++;
    
    for(int i = 0; i < k; i++) {
        if(lower == arr.end()) {
            result.push_back(upper[-1]);
            upper--;
        } else if(upper == arr.end()) {
            result.push_back(lower[-1]);
            lower--;
        } else {
            if(abs(x - lower[-1]) < abs(x - upper[-1]))
                result.push_back(lower[-1]);
            else
                result.push_back(upper[-1]);
            
            if(lower[-1] == upper[-1])
                upper--;
            else
                lower++;
        }
    }
    
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
}

int main() {
    int n, k, x;
    cin >> n >> k >> x;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    findKClosest(arr, n, k, x);
    
    return 0;
}