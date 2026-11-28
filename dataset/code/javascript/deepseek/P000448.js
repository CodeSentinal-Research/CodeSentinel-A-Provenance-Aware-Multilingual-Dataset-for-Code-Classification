Here's the JavaScript code for the given problem:

function squareRoot(n) {
    if (n < 0) {
        throw new Error('Input must be non-negative.');
    }

    let start = 0;
    let end = Math.min(n, 46340); // 46340 is the largest square number less than n.

    while (start < end) {
        const mid = Math.floor((start + end) / 2);

        if (mid * mid === n) {
            return mid;
        } else if (mid * mid < n) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }

    return start;
}

This code implements binary search for finding the square root of a number. It iteratively divides the search interval [start, end] in half. If the middle square is equal to n, return it. If the middle square is less than n, set start = mid + 1. Otherwise, set end = mid. The process repeats until start is equal to end.

The input is a non-negative integer n. It is handled by checking if n is less than 0 and throwing an error if it is.

The time complexity is O(log n), which is faster than the linear search time complexity O(n), and the space complexity is O(1), as it only uses a constant amount of space.