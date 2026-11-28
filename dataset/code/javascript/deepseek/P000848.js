Here is the JavaScript code to solve the problem:

/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumSize = function(nums) {
    let n = nums.length;
    let max = nums[n - 1];
    let l = 0, r = max;
    while (l < r) {
        let mid = l + ((r - l) >> 1);
        if (check(nums, mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
};

const check = (nums, limit) => {
    let sum = 0;
    for (let num of nums) {
        sum += Math.ceil(num / limit);
    }
    return sum <= nums.length;
}

In this code, we use a binary search to find the minimum possible maximum value. We start with the maximum value and try to find a value that is less than or equal to it. If it is possible, then we update the right hand limit (r) otherwise we update the left hand limit (l). The binary search algorithm in this code finds the minimum value of maximum element after performing any number of operations.