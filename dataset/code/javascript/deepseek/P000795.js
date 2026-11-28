Here's a simple JavaScript code for the problem.

function countSubarrays(nums, k, n) {
    let count = 0;
    for (let i = 0; i < nums.length; i++) {
        let sum = nums[i];
        if (sum % k === 0) {
            count++;
        }
        for (let j = i + 1; j < nums.length; j++) {
            sum += nums[j];
            if (sum % k === 0) {
                count++;
            }
        }
    }
    return count;
}
This solution works by iterating over the input array and summing up all numbers from each position. If the sum is divisible by `k`, it increments a counter. Then it iterates over the rest of the array, summing up numbers from each position again and checking if the sum is divisible by `k`. This process is repeated for each position in the array.

Note that this solution will work under the constraints given in the problem, but it's not the most efficient solution. It has a time complexity of O(n^2), which makes it inefficient for larger inputs.

For a more efficient solution, we can use a prefix sum and a hashmap to store the frequency of remainders when a number is divided by `k`. The frequency of a remainder can be used as the count of valid subarrays ending at a particular index.

Here is the optimized solution:

function countSubarrays(nums, k, n) {
    let count = 0;
    let modCount = new Map();
    let sum = 0;

    modCount.set(0, 1);

    for (let num of nums) {
        sum += num;
        let remainder = sum % k;
        if (remainder < 0) {
            remainder += k;
        }

        count += modCount.get(remainder, 0);
        modCount.set(remainder, (modCount.get(remainder, 0) || 0) + 1);
    }

    return count;
}

This solution works by iterating over the input array and summing up all numbers. For each number, it computes its remainder when divided by `k`. If the remainder is negative, it adds `k` to it to ensure it is non-negative. It then increments the count of valid subarrays ending at the current index by the frequency of the remainder in the hashmap. If the remainder is not in the hashmap, it defaults to 0.

The time complexity of this solution is O(n), which is much more efficient for larger inputs.