Here's the JavaScript code that computes Euler's Totient Function φ(N). 

function phi(n) {
    let result = n;
    for (let i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            result -= result / i;
        }
    }
    if (n > 1) {
        result -= result / n;
    }
    return result;
}

This function starts with the assumption that n is a prime number, and then iteratively divides n by all factors of n. If a factor is found, then the function decreases the count of the factor by adding all numbers less than the square of that factor to the result, until n is no longer divisible by i. If the loop ends with n being a prime number greater than 1, then the function subtracts one from the result. The final result is the totient function value of n.

Note: This function has been simplified and will only handle small inputs due to performance considerations. For larger inputs, you may need to use a more complex approach.