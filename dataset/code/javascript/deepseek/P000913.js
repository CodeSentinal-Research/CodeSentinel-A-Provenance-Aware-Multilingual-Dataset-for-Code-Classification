Here is the JavaScript code to compute the binomial coefficient modulo a prime number:

function binomialCoeffModPrime(n, r, P) {
    if (n < r || n < 0 || r < 0 || P < 2) {
        throw new Error('Invalid input.');
    }

    let denominator = 1;
    for (let i = 1; i <= r; i++) {
        denominator = (denominator * (n - i + 1)) % P;
    }

    let numerator = 1;
    for (let i = 1; i <= n - r; i++) {
        numerator = (numerator * i) % P;
    }

    return (numerator * denominator) % P;
}

This code first checks if the input values are valid. Then it computes the denominator and the numerator using the formula for combinations (nCr mod p) = (n-r)! / (r!(n-n/r)!) mod p.

This code assumes that the prime number P is greater than 1, and the integers n, r are within the allowed range (0 <= r <= n <= 10^6). The modulo operation is applied in the denominator and numerator computations to ensure the result is within the modulo of P.