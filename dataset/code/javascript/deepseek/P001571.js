Here is a simple JavaScript solution that handles the problem:

function maxDifference(arr, k) {
    if (k > arr.length || k < 1) {
        throw new Error('Invalid window size');
    }

    const n = arr.length;
    if (n === 0 || k === 0) {
        throw new Error('Invalid input');
    }

    const windowedDifferences = [];

    for (let i = 0; i < n - k + 1; i++) {
        const windowEnd = i + k - 1;
        const maxInWindow = Math.max(...arr.slice(i, windowEnd + 1));
        const minInWindow = Math.min(...arr.slice(i, windowEnd + 1));
        const difference = maxInWindow - minInWindow;
        windowedDifferences.push(difference);
    }

    return windowedDifferences;
}

This function first checks if the window size `k` is greater than the array length or less than 1. If it is, it throws an error. Then, it checks if the array is empty or the window size is 0. If either of these is the case, it throws an error.

It then creates an empty array `windowedDifferences` to store the differences for each window.

It then iterates over each possible starting point `i` for the window, up to `n - k + 1` (to account for the case where `k` is the total length of the array). For each window, it extracts the maximum and minimum values within the window, calculates the difference, and stores this difference in `windowedDifferences`.

Finally, it returns `windowedDifferences`.