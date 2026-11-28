Here's a simple JavaScript function that counts the digits in a given integer:

function countDigits(N) {
    if (N < 0 || N > 10^18) {
        throw new Error('Invalid input. Please provide an integer between 0 and 10^18.');
    }

    if (N === 0) {
        return 1;
    }

    let count = 0;

    while (N > 0) {
        N /= 10;
        count++;
    }

    return count;
}

This function first checks if the input is valid. If it's not, it throws an error. If it is, it enters a loop where it continuously divides the input by 10 (floor division to remove the decimal part) and increments the count until the input is 0. At the end of the function, it returns the count of digits.