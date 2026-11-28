Here is a JavaScript code snippet that calculates A^φ(N) mod N using Euler's Theorem:

function powerModulo(A, N) {
    // Calculate gcd of A and N
    let gcd = A % N;
    
    // While gcd is not 1, keep dividing A by gcd
    while (gcd !== 1) {
        A = A / gcd;
        gcd = A % N;
    }
    
    // Return A^φ(N) mod N
    return Math.pow(A, phi(N)) % N;
}

// Function to calculate phi(N)
function phi(N) {
    let result = N;
    for (let i = 2; i * i <= N; i++) {
        if (N % i === 0) {
            while (N % i == 0) {
                N = N / i;
            }
            result = result - result / i;
        }
    }
    if (N > 1) {
        result = result - result / N;
    }
    return result;
}

This code first calculates the greatest common divisor (gcd) of A and N. Then, it calculates A^φ(N) mod N by repeatedly dividing A by the gcd and updating the gcd. The phi function is used to calculate φ(N) which is the Euler's totient function. It is calculated by finding all numbers from 2 up to sqrt(N) that divide N and counting them.