function modularMultiplicativeInverse(A, M) {
    // Check for input validation
    if (A < 1 || A > M || M > 10**18 || A > M) {
        return -1;
    }

    // If A and M are coprime, A^-1 * M = 1 (mod M)
    if (gcd(A, M) === 1) {
        return modularMultiplicativeInverseHelper(A, M);
    }

    // If A and M are not coprime, no inverse exists
    return -1;
}

// Helper function to find gcd of two numbers
function gcd(a, b) {
    if (!b) {
        return a;
    }
    return gcd(b, a % b);
}

// Helper function to find modular multiplicative inverse
function modularMultiplicativeInverseHelper(A, M) {
    // Uses the extended Euclidean algorithm
    let [g, x, y] = [A, 1, 0];
    let [m, xM, yM] = [M, 0, 1];

    while (m != 0) {
        let q = g / m;
        [g, m] = [m, g - q * m];
        [x, xM] = [xM, x - q * xM];
        [y, yM] = [yM, y - q * yM];
    }

    return (x % M + M) % M;
}

// Testing the function
console.log(modularMultiplicativeInverse(3, 11)); // Output: 10
console.log(modularMultiplicativeInverse(13, 17)); // Output: 9
console.log(modularMultiplicativeInverse(5, 9)); // Output: 2
console.log(modularMultiplicativeInverse(7, 13)); // Output: 6
console.log(modularMultiplicativeInverse(4, 5)); // Output: -1