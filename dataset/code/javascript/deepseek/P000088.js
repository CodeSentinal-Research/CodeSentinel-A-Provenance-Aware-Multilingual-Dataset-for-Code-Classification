Here is a simple JavaScript function to check whether a number is a perfect square:

function isPerfectSquare(n) {
    if (n < 1 || n > 10^9) {
        console.log("Invalid input. Please enter a positive integer between 1 and 10^9.");
        return;
    }
    if ((Math.sqrt(n) % 1) === 0) {
        console.log("Perfect Square");
    } else {
        console.log("Not Perfect Square");
    }
}

In this function, we first check if the input number n is within the valid range (1 ≤ n ≤ 10^9). If not, we output an error message and return early.

Then, we use the Math.sqrt method to find the square root of n. We check if the remainder when dividing by 1 is 0, which would indicate that n is a perfect square (in other words, n is an integer). If it is, we print "Perfect Square"; otherwise, we print "Not Perfect Square".