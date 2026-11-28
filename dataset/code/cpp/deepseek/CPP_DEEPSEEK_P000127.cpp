#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int* heights = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    int maxArea = 0;
    int left = 0;
    int right = n - 1;
    while (left < right) {
        int width = right - left;
        int area = width * min(heights[left], heights[right]);
        maxArea = max(maxArea, area);
        if (heights[left] < heights[right]) {
            left++;
        } else {
            right--;
        }
    }
    cout << maxArea << endl;
    delete[] heights;
    return 0;
}