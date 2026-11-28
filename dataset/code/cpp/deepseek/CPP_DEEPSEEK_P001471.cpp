Here is the complete C++ code for the problem:

#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) {
    int max_area = 0;
    int left = 0;
    int right = height.size() - 1;

    while (left < right) {
        max_area = max(max_area, min(height[left], height[right]) * (right - left));

        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return max_area;
}

int main() {
    int n;
    cin >> n;

    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    cout << maxArea(height);

    return 0;
}
This program works by using two pointers, one at the start of the array and the other at the end. The area between the two lines at any given position is calculated using the formula min(height[left], height[right]) * (right - left), and the maximum of all these areas is returned as the maximum water that can be contained. If height[left] < height[right], it means that we can't contain any water between these two lines, so we move the left pointer to the right. If height[left] > height[right], it means that we can't contain any water between these two lines, so we move the right pointer to the left. We continue this process until the left pointer is no longer less than the right pointer.