Here is a simple JavaScript code snippet that uses Fermat's little theorem to compute the modulus of a power (A^B mod M) efficiently.

function modularExponentiation(A, B, M) {
    if (A === 0) {
        return 0;
    }

    if (B === 0) {
        return 1;
    }

    let power = modularInverse(B, M);
    let result = Math.pow(A, power) % M;

    return result;
}

function modularInverse(B, M) {
    B = B % M;

    for (let x = 1; x <= M; x++) {
        if ((B * x) % M === 1) {
            return x;
        }
    }

    return -1;
}

This code first checks if B is 0, as 0^0 is undefined. Then it calculates the modular multiplicative inverse of B under mod M using the Fermat's little theorem. If B is not 0, it calculates (A^B) mod M using the Math.pow method and then takes the result modulo M.

Please note that this solution has a high time complexity due to the modular multiplicative inverse computation, so it may not be suitable for large inputs.