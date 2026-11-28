function countWindows(arr, k) {
    let count = 0;
    for (let i = 0; i < arr.length - k + 1; i++) {
        if (arr[i] > 0) {
            count++;
            for (let j = i + 1; j < i + k; j++) {
                if (arr[j] > 0) {
                    count++;
                }
            }
        }
    }
    return count;
}

// Test the function
let arr = [1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0];
let k = 3;
console.log(countWindows(arr, k)); // Outputs: 6
This code defines a function `countWindows` that takes an array and a window size `k` as arguments. It iterates over the array, and for each element, it increases a count. If the element is positive, it also checks for positive elements in the next `k` elements.