Here is the JavaScript code to verify Bézout's Identity:

function verifyBézoutIdentity(A, B, X, Y) {
    if (Math.gcd(A, B) % (A * X + B * Y) === 0) {
        console.log(true);
    } else {
        console.log(false);
    }
}

In this code, we are creating a function named `verifyBézoutIdentity` that takes four parameters: A, B, X, and Y. We are using `Math.gcd(A, B)` to find the greatest common divisor of A and B. Then we are checking if the remainder of the Euclidean division of A and B by (A * X + B * Y) is zero. If the remainder is zero, then we print true; otherwise, we print false.

You can use this function by calling it with the values of A, B, X, and Y. For example, `verifyBézoutIdentity(2, 3, 1, 2);` would print `true` if the pair (X, Y) satisfies Bézout's Identity, and `false` otherwise.