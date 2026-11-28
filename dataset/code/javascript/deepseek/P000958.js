Here is the JavaScript code:

function minimumPositiveBézoutSolution(A, B) {
    if (A === 0) {
        return [B, 0];
    } else if (B === 0) {
        return [0, A];
    } else {
        let gcd = gcd(A, B);
        A = A / gcd;
        B = B / gcd;
        return [A, B];
    }
}

function gcd(a, b) {
    if (!b) {
        return a;
    }
    return gcd(b, a % b);
}

In this code, we first check if A is 0 or B is 0. If either is 0, we return the other as the solution. Otherwise, we use the Euclidean algorithm to find the greatest common divisor of A and B, and then divide A and B by the greatest common divisor to find the smallest positive integer X and Y.

Please note that this code only works for positive integers. If A and B can be negative, you will need to handle that separately. Also, the input is given in the form of integers. If you want to handle it as a floating point number, you can modify the function accordingly.

Also, this code uses the gcd function to find the greatest common divisor of two numbers, which is a standard method for finding the greatest common divisor of two integers. This function uses the Euclidean algorithm to find the greatest common divisor.