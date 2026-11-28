function binarySearchFirstOccurrence(arr, target) {
    let start = 0;
    let end = arr.length - 1;
    let result = -1;

    while (start <= end) {
        const mid = Math.floor((start + end) / 2);
        if (arr[mid] === target) {
            result = mid;
            end = mid - 1;
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return result;
}