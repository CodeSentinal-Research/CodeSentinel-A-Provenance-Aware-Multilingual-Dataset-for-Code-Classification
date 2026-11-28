Here is a simple JavaScript function that generates all N-digit numbers whose digits are strictly increasing from left to right.

function generateNumbers(n) {
    if (n < 1 || n > 9) {
        console.log('Invalid input. Input should be between 1 and 9.');
        return;
    }

    let num = Math.pow(10, n - 1);

    while (num < Math.pow(10, n)) {
        console.log(num);
        num++;
    }
}

generateNumbers(3);  // For example, to generate all N-digit numbers with 3 digits, you can call this function with 3 as input.

In this code, we first check if the input is valid. If the input is not in the range 1 to 9, we print an error message and return.

Next, we calculate the smallest possible number with `n` digits using `Math.pow(10, n - 1)`.

Then, we enter a loop that continues until we reach the largest possible number with `n` digits (i.e., `Math.pow(10, n) - 1`). Inside the loop, we print the current number and then increment it by 1.

Please note that the numbers printed out are N-digit numbers, not N digits.

Also, make sure to call this function with an integer as an argument to get the N-digit numbers.