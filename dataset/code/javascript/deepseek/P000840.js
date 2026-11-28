Here is a simple JavaScript solution for the problem. This solution uses a Binary Search approach to find the minimum possible maximum number of balls in any bag.

/**
 * @param {number} n
 * @param {number[]} nums
 * @param {number} maxOperations
 * @return {number}
 */
function minimumSize(n, nums, maxOperations) {
    let left = 1;
    let right = Math.max(...nums);
    while(left < right) {
        let mid = Math.floor((left + right) / 2);
        let operations = 0;
        let maxBalls = 0;
        for(let num of nums) {
            operations += Math.ceil(num / mid) - 1;
            maxBalls = Math.max(maxBalls, Math.ceil(num / mid));
        }
        if(operations <= maxOperations) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

This code first finds the maximum number in the input array. Then it uses a binary search to find the minimum possible maximum number of balls in any bag. The binary search finds the minimum possible maximum number of balls in any bag by checking if the current mid value can reduce the number of operations. If it can, it moves the right pointer to mid, otherwise it moves the left pointer to mid + 1. The loop continues until the left equals to right, which means that the answer is right.

Please note that this solution assumes that the operations to split a bag into two non-empty bags are not counted towards the maxOperations. If the operations to split a bag into two non-empty bags are counted, you would need to modify the code to account for this.