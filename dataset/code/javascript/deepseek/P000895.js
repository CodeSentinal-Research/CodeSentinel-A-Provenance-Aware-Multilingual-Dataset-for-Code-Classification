Here's the JavaScript code for the given problem:

function leastCommonMultiple(A, B) {
    if (A < 1 || B < 1 || A > 10e18 || B > 10e18) {
        throw new Error('Input should be positive integers less than or equal to 10^18');
    }

    if (A === 1 || B === 1) {
        return 1;
    }

    if (A === B) {
        return A;
    }

    if (A > B) {
        return A / gcd(A, B);
    }

    return B / gcd(A, B);
}

function gcd(a, b) {
    if (b === 0) {
        return a;
    }

    return gcd(b, a % b);
}
This code first checks if the input numbers are within the constraints. If they are not, it throws an error. Then it checks if either number is 1. If so, it returns 1. If the numbers are the same, it returns the number itself.

Next, it checks if A is greater than B. If it is, it returns the result of A divided by the greatest common divisor of A and B. Otherwise, it returns the result of B divided by the greatest common divisor of A and B.

The function gcd(a, b) calculates the greatest common divisor of two numbers. It uses the Euclidean algorithm, which works by repeatedly replacing a and b with b and a%b (the remainder when a is divided by b), until a is replaced by b.