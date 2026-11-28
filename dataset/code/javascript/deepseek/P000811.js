Here is the JavaScript code:

function guessNumber(n) {
    let start = 1;
    let end = n;

    while (start <= end) {
        let mid = Math.floor((start + end) / 2);
        if (guess(mid) === 0) {
            return mid;
        } else if (guess(mid) === 1) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
}

In this code, we use binary search to find the hidden number in the given range. The guess function is assumed to be defined elsewhere in your code. The guess function is expected to return -1, 1, or 0 based on whether the given number is lower, higher, or correct.