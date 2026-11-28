function maxArea(height) {
    let max = 0;
    let left = 0;
    let right = height.length - 1;
    while (left < right) {
        max = Math.max(max, Math.min(height[left], height[right]) * (right - left));
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return max;
}

console.log(maxArea([1,8,6,2,5,4,8,3,7])); // Output: 49
In this code, we initialize the maximum area `max` and two pointers, `left` and `right`, to the start and end of the array respectively. We then enter a while loop that continues until `left` is not less than `right`. Inside the loop, we calculate the area between the shorter line and the current pair of pointers and update `max` if necessary. If the shorter line is to the left of the longer line, we move the `left` pointer to the next index to the right. Otherwise, we move the `right` pointer to the previous index. Finally, we return `max`.