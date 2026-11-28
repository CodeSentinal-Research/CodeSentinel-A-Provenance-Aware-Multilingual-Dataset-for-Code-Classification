function linearSearchRecursive(nums, target) {
    if (nums.length === 0) {
        return false;
    } else {
        if (nums[0] === target) {
            return true;
        } else {
            return linearSearchRecursive(nums.slice(1), target);
        }
    }
}