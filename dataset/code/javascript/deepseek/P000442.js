function searchInRotatedArray(arr, target) {
    let pivot = findPivot(arr, 0, arr.length - 1);

    if (arr[pivot] === target) {
        return pivot;
    }
    if (arr[0] <= target) {
        return binarySearch(arr, 0, pivot, target);
    }
    return binarySearch(arr, pivot + 1, arr.length - 1, target);
}

function findPivot(arr, low, high) {
    if (high < low) {
        throw new Error("Array is not rotated");
    }
    if (high == low) {
        return low;
    }
    let mid = Math.floor((low + high) / 2);
    if (mid < high && arr[mid] < arr[mid + 1]) {
        return mid;
    }
    if (mid > low && arr[mid] < arr[mid - 1]) {
        return (mid - 1);
    }
    if (arr[low] >= arr[mid]) {
        return findPivot(arr, low, mid - 1);
    }
    return findPivot(arr, mid + 1, high);
}

function binarySearch(arr, low, high, target) {
    if (high < low) {
        return -1;
    }
    let mid = Math.floor((low + high) / 2);
    if (arr[mid] === target) {
        return mid;
    }
    if (arr[mid] > target) {
        return binarySearch(arr, low, mid - 1, target);
    }
    return binarySearch(arr, mid + 1, high, target);
}

const arr = [4, 5, 6, 7, 0, 1, 2];
const target = 0;
console.log(searchInRotatedArray(arr, target)); // Output: 4