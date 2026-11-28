function maxArea(heights) {
    let max = 0;
    let left = 0;
    let right = heights.length - 1;

    while (left < right) {
        let heightLeft = heights[left];
        let heightRight = heights[right];

        let distance = right - left;
        let minHeight = Math.min(heightLeft, heightRight);

        max = Math.max(max, minHeight * distance);

        if (heightLeft < heightRight) {
            left++;
        } else {
            right--;
        }
    }

    return max;
}
This code uses two pointers (left and right) to find the maximum area of water that can be contained within the array of heights. The area of water is calculated as the shorter height between the two pointers (times the distance between them). If the left height is smaller than the right height, we move the left pointer to the right; otherwise, we move the right pointer to the left. This process is repeated until the left pointer is no longer less than the right pointer, indicating that we have found the maximum area.