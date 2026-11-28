Sure, here is the JavaScript code to solve the problem:

function minMaxDifference(nums, p) {
    nums.sort((a, b) => a - b);
    let left = 0;
    let right = nums.length - p;
    let minDiff = Infinity;
    while (left < right) {
        minDiff = Math.min(minDiff, nums[right] - nums[left]);
        left++;
        right--;
    }
    return minDiff;
}

console.log(minMaxDifference([1, 5, 8, 10], 3));

This code first sorts the input array in ascending order. Then it initializes the `left` pointer to the start of the array and the `right` pointer to the `p`-th element from the end of the array. It keeps moving the `left` pointer to the right and the `right` pointer to the left while minimizing the difference between the `right` and `left` elements. The final minimum difference is the minimum of all differences found so far. This approach works because the pairs that are selected for the final result will be the pairs with the smallest difference, and since the array is sorted, we can always take the pair with the largest difference.