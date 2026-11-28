function nextGreaterElement(nums) {
    const n = nums.length;
    const res = new Array(n).fill(-1);
    const stack = [];

    for (let i = n - 1; i >= 0; i--) {
        // Maintain monotonic stack property by popping smaller elements
        while (stack.length && stack[stack.length - 1] <= nums[i]) {
            stack.pop();
        }
        if (stack.length) res[i] = stack[stack.length - 1];
        stack.push(nums[i]);
    }
    return res;
}

module.exports = { nextGreaterElement };