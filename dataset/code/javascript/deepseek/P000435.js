function binarySearch(arr, target, start, end) {
    if (start > end) return false;
    const mid = Math.floor((start + end) / 2);
    if (arr[mid] === target) return true;
    if (arr[mid] > target) return binarySearch(arr, target, start, mid - 1);
    return binarySearch(arr, target, mid + 1, end);
}

function countOccurrences(input) {
    const [N, target] = input[0].split(' ').map(Number);
    const arr = input[1].split(' ').map(Number);
    arr.sort((a, b) => a - b);
    let start = 0;
    let end = N - 1;
    let frequency = 0;
    while (start <= end) {
        const mid = Math.floor((start + end) / 2);
        if (binarySearch(arr, target, start, mid)) {
            frequency++;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return frequency;
}
This code firstly implements a binary search function `binarySearch` that searches for a target in a sorted array. The binary search algorithm is a very efficient way to find an element in a sorted array, as it uses a divide and conquer strategy.

Then, the `countOccurrences` function takes the input and processes it. It firstly splits the input into N and arr, and then sorts arr. It then calls binarySearch for each midpoint of the sorted array, starting from the leftmost point. If the target is found, it increments the frequency and moves the search to the rightmost part of the array. If the target is not found, it moves to the leftmost part of the array. This process continues until the search is complete.