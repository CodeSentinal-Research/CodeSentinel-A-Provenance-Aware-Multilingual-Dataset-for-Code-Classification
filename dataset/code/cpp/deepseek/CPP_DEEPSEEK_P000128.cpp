Here is the C++ solution:

#include <iostream>
#include <vector>

using namespace std;

int trapRainWater(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int leftMax = 0, rightMax = 0;
    int res = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] > leftMax) leftMax = height[left];
            else res += leftMax - height[left];
            left++;
        }
        else {
            if (height[right] > rightMax) rightMax = height[right];
            else res += rightMax - height[right];
            right--;
        }
    }

    return res;
}

int main() {
    int n;
    cin >> n;

    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    cout << trapRainWater(height);

    return 0;
}
This code reads an integer `n`, followed by `n` integers, representing the height of the bars. The function `trapRainWater` calculates the maximum height of the left and right bars from each end and the total amount of water trapped between the two bars.