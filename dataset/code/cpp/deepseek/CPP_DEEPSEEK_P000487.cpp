#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int trapRainWater(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    int l = 0, r = n - 1;
    int lmax = 0, rmax = 0;
    int res = 0;

    while (l < r) {
        if (height[l] < height[r]) {
            if (height[l] > lmax) lmax = height[l];
            else res += lmax - height[l];
            l++;
        }
        else {
            if (height[r] > rmax) rmax = height[r];
            else res += rmax - height[r];
            r--;
        }
    }

    return res;
}

int main() {
    vector<int> height = {1, 2, 1, 3, 2, 1, 2, 1, 3, 2, 1, 2, 3, 2, 1, 2, 3, 2, 1, 2, 3};
    cout << trapRainWater(height) << endl;
    return 0;
}