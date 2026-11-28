Sure, here is the JavaScript code to solve the problem:

function isDivisibleBy9(N) {
    if (N % 9 === 0) {
        console.log(true);
    } else {
        console.log(false);
    }
}

This function takes an integer N as input and checks if it is divisible by 9. It does this by using the modulus operator (`%`), which returns the remainder of the division of the first operand by the second. If the remainder is 0, then the number is divisible by 9. Otherwise, it's not.