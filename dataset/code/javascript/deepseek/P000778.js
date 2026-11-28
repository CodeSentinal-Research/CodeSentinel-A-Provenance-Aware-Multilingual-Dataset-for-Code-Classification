The problem is a combination problem, and there is a well-known algorithm to solve it in polynomial time, called the Tug of War (also known as the Partition problem). This algorithm works by first sorting the array, then trying to divide the array into two subsets such that their sums differ by at most one.

Here is a JavaScript solution that uses a brute force approach to find the minimum absolute difference:

function tugOfWar(nums) {
    let n = nums.length;
    if (n < 2) {
        return null;
    }
    nums.sort((a, b) => a - b);
    let left = nums[0];
    let right = nums[1];
    let minAbsDiff = Math.abs(nums[n - 1] + nums[n - 2] - left - right);
    for (let i = 2; i < n; i += 2) {
        left += nums[i];
        right = nums[n - 1] - left;
        let curAbsDiff = Math.abs(left + right - nums[i - 1] - nums[i]);
        if (curAbsDiff < minAbsDiff) {
            minAbsDiff = curAbsDiff;
            left -= nums[i - 1];
            right += nums[i];
        }
    }
    return minAbsDiff;
}

This code first sorts the input array. Then it tries to divide the array into two subsets. For each iteration, it tries to add one element to the left subset and subtract one element from the right subset. The minimum absolute difference is updated if the current absolute difference is smaller.

Please note that this algorithm is not optimal and may not always give the minimum absolute difference. The time complexity of this algorithm is O(n^2) due to the nested loop.