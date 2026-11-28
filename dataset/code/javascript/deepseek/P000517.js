function maxWidthRamp(nums) {
    const stack = [];
    for (let i = 0; i < nums.length; i++) {
        if (stack.length === 0 || nums[i] < nums[stack[stack.length - 1]]) {
            stack.push(i);
        }
    }

    let maxWidth = 0;
    for (let i = nums.length - 1; i >= 0; i--) {
        while (stack.length > 0 && nums[i] >= nums[stack[stack.length - 1]]) {
            let width = i - stack.pop();
            maxWidth = Math.max(maxWidth, width);
        }
    }

    return maxWidth;
}