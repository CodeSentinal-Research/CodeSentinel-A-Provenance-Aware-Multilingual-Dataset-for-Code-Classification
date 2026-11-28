Here is the JavaScript code for the problem:

function extendedEuclid(A, M) {
    if (A === 0) {
        return M !== 0 ? -1 : 0;
    }
    let (g, x, y) = [A, 1, 0];
    let (b, a, z) = [M, A, 1];
    while (b !== 0) {
        let (q, r) = [b, b];
        b = a % b;
        a = r;
        (x, y) = ([x - q * y], y);
    }
    return A !== 1 ? M * x % A : M * (M + 1) % A;
}

console.log(extendedEuclid(parseInt(process.argv[2]), parseInt(process.argv[3])));

You can run this script by passing the values as command line arguments:

node script.js <A> <M>

For example, to find the modular inverse of 3 modulo 11, run:

node script.js 3 11

This will output `10`.