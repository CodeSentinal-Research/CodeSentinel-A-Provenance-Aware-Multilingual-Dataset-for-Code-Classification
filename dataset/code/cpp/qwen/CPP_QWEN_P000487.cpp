#include <iostream>
#include <vector>
using namespace std;
int trap(vector<int>& height) {
    int l=0, r=height.size()-1;
    int left_max=0, right_max=0;
    int water = 0;
    while(l < r) {
        if(height[l] < height[r]) {
            if(height[l] >= left_max) left_max = height[l];
            else water += left_max - height[l];
            l++;
        } else {
            if(height[r] >= right_max) right_max = height[r];
            else water += right_max - height[r];
            r--;
        }
    }
    return water;
}
int main() {
    int n; cin >> n;
    vector<int> height(n);
    for(int i=0; i<n; i++) cin >> height[i];
    cout << trap(height) << endl;
    return 0;
}
