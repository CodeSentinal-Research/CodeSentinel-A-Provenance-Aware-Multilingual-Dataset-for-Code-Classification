function binarySearch(nums, target) {
    let start = 0;
    let end = nums.length - 1;
    return recursiveBinarySearch(nums, target, start, end);
}

function recursiveBinarySearch(nums, target, start, end) {
    if (start > end) {
        return -1;
    }

    let mid = Math.floor((start + end) / 2);

    if (nums[mid] === target) {
        return mid;
    }

    if (nums[mid] > target) {
        return recursiveBinarySearch(nums, target, start, mid - 1);
    } else {
        return recursiveBinarySearch(nums, target, mid + 1, end);
    }
}