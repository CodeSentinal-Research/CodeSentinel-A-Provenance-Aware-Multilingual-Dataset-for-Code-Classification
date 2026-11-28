Here is the JavaScript code:

function findMaxXOR(nums) {
    let max = 0, mask = 0;
    for (let i = 0; i < 32; i++) {
        if ((mask ^ (1 << i)) in nums) {
            let maxNum = Math.max(...nums.filter(n => (n & (1 << i))));
            max = Math.max(max, maxNum ^ mask);
        }
    }
    return max;
}

This function works by trying to find a set bit in each position of a mask, if it exists in the input array. Then, it checks if there's another number in the array that has the same set bits at this position, and updates the max value accordingly.