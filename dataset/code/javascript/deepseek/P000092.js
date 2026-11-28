Here is the JavaScript code for the problem:

function sumOfAP(a, d, n) {
    if (n < 1 || n > 1000) {
        throw new Error('n should be between 1 and 1000');
    }
    if (!Number.isInteger(a) || !Number.isInteger(d) || a === undefined || d === undefined || n === undefined) {
        throw new Error('a, d and n should be integers');
    }
    if (a > d * (n - 1)) {
        throw new Error('a should be less or equal to d times (n-1)');
    }
    if (d === 0) {
        throw new Error('d should not be 0');
    }
    return a + (n - 1) * d / 2;
}
This function takes three arguments, a and d (the first term and the common difference), and n (the number of terms). It then checks if the provided values are valid and if they are, it calculates and returns the sum of the AP series.