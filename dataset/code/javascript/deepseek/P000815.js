function findFirstAndLastOccurrence(nums, target) {
    let firstOccurrence = binarySearch(nums, target, true);
    if (firstOccurrence === -1) return [-1, -1];
    let lastOccurrence = binarySearch(nums, target, false);
    return [firstOccurrence, lastOccurrence];
}

function binarySearch(nums, target, findFirst) {
    let start = 0, end = nums.length - 1;
    let ans = -1;
    while (start <= end) {
        let mid = Math.floor(start + (end - start) / 2);
        if (nums[mid] === target) {
            ans = mid;
            if (findFirst) end = mid - 1;
            else start = mid + 1;
        } else if (nums[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}
This code first performs a binary search for the first occurrence of the target in the array. If the target is not found, it returns -1. Then it continues the binary search from the found index to find the last occurrence. It uses a boolean variable to decide if the search should continue from the found index or not. In case the target is not found, it returns -1.