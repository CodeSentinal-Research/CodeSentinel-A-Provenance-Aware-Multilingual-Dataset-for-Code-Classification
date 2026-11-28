function isMaxHeap(nums, i = 0, size = nums.length) {
    // Base case: if the array is empty, it's a max heap
    if (i >= size) {
        return true;
    }

    // Check the children nodes (left child and right child)
    if (i * 2 + 1 < size) {
        if (nums[i] < nums[i * 2 + 1]) {
            return false;
        }
        if (!isMaxHeap(nums, i * 2 + 1, size)) {
            return false;
        }
    }

    if (i * 2 + 2 < size) {
        if (nums[i] < nums[i * 2 + 2]) {
            return false;
        }
        if (!isMaxHeap(nums, i * 2 + 2, size)) {
            return false;
        }
    }

    // If no children violations have been found, the array is a max heap
    return true;
}