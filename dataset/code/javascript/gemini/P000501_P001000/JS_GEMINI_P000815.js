// Performs search to locate target element within the given collection.
function searchRange(nums, target) {
    function findBound(isFirst) {
        let left = 0, right = nums.length - 1;
        let ans = -1;
        // Binary search loop to narrow down range
        while (left <= right) {
            // Calculate midpoint to prevent potential overflow
            const mid = Math.floor(left + (right - left) / 2);
            if (nums[mid] === target) {
                ans = mid;
                if (isFirst) right = mid - 1;
                else left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }

    return [findBound(true), findBound(false)];
}

module.exports = { searchRange };