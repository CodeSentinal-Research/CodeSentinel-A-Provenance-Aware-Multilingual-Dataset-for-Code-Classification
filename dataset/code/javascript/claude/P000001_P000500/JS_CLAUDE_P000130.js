function nextSmallerElement(nums) {
    const n = nums.length, res = new Array(n).fill(-1), stack = [];
    for (let i = 0; i < n; i++) {
        while (stack.length && nums[stack[stack.length-1]] > nums[i])
            res[stack.pop()] = nums[i];
        stack.push(i);
    }
    return res;
}
module.exports = { nextSmallerElement };
