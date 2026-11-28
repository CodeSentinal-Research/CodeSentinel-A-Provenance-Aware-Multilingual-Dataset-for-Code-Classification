Here is the JavaScript code for the problem:

let n;
n = parseInt(readline());

function isBeautifulArrangement(i, j) {
    for (let k = i; k <= j; k++) {
        if (i % k == 0 || k % i == 0) {
            return false;
        }
    }
    return true;
}

function countArrangement(i, j) {
    if (i == j) {
        return 1;
    }

    let count = 0;
    for (let k = i; k <= j; k++) {
        if (isBeautifulArrangement(i, k) && isBeautifulArrangement(k, j)) {
            count += countArrangement(i, k - 1) * countArrangement(k + 1, j);
        }
    }

    return count;
}

console.log(countArrangement(1, n));

In this code, `isBeautifulArrangement` function checks whether a number is divisible by another number or not. The `countArrangement` function counts the total number of beautiful arrangements for a given range. It uses recursion to find the number of arrangements.