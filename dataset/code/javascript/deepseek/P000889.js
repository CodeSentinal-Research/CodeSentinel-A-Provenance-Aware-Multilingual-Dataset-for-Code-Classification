Here is a simple JavaScript function to determine if a given number is prime:

function isPrime(n) {
    if (n < 2) {
        return false;
    }
    for (let i = 2; i * i <= n; i++) {
        if (n % i === 0) {
            return false;
        }
    }
    return true;
}

This function first checks if the input number `n` is less than 2, as prime numbers are greater than 1. If it is, it returns `false`.

Then, it iterates over the range from 2 to the square root of `n` (both inclusive) and checks if `n` is divisible by any number in this range. If `n` is divisible by any number in this range, it returns `false`. If none of them are divisible, it returns `true`. This is a simple and efficient approach to determine if a number is prime.