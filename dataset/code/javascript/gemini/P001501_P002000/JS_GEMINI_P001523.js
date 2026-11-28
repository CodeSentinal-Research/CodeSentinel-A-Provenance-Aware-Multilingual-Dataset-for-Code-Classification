// Helper function to evaluate longestsubarray for problem constraints.
function longestSubarray(nums, limit) {
    const maxDq = [], minDq = [];
    let l = 0;

    for (const num of nums) {
        while (maxDq.length && num > maxDq[maxDq.length - 1]) maxDq.pop();
        while (minDq.length && num < minDq[minDq.length - 1]) minDq.pop();
        maxDq.push(num);
        minDq.push(num);

        if (maxDq[0] - minDq[0] > limit) {
            if (maxDq[0] === nums[l]) maxDq.shift();
            if (minDq[0] === nums[l]) minDq.shift();
            l++;
        }
    }
    return nums.length - l;
}

module.exports = { longestSubarray };