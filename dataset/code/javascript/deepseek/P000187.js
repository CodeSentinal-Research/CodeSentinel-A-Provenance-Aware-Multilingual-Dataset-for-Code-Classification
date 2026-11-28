Sure, here is the JavaScript code that will solve the problem:

function findSmallestMissingPositive(arr) {
    let n = arr.length;
    if (n == 0) {
        return 1;
    }

    let positiveCount = 0;
    for (let i = 0; i < n; i++) {
        if (arr[i] > 0) {
            positiveCount++;
        }
    }

    if (positiveCount == 0) {
        return 1;
    }

    let containsOne = false;
    for (let i = 0; i < n; i++) {
        if (arr[i] == 1) {
            containsOne = true;
        }
        if (arr[i] <= 0) {
            arr[i] = 1;
        }
    }

    if (!containsOne) {
        return 1;
    }

    for (let i = 0; i < n; i++) {
        let a = Math.abs(arr[i]);
        if (a == n) {
            arr[0] = -Math.abs(arr[0]);
        } else {
            arr[a] = -Math.abs(arr[a]);
        }
    }

    for (let i = 1; i < n; i++) {
        if (arr[i] > 0) {
            return i;
        }
    }

    if (arr[0] > 0) {
        return n;
    }

    return n + 1;
}
This code first checks if the array is empty and if so, returns 1. It also checks if there is at least one positive number in the array. If not, it returns 1. After that, it checks if the array contains only ones, and if so, returns 1. 

Then, for each element in the array, it sets the corresponding index to -abs(element) because in the array, the index represents the number at that index and the value at that index is the positive number that has not been found yet.

Finally, for each remaining positive number in the array, if the number is larger than the array length, it means that the number is not in the array (meaning it was not found), so it returns the array length (n+1) as the smallest positive missing number. If no such number is found, it returns the array length + 1 as the smallest positive missing number.