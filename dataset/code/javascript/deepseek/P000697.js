Here's a JavaScript solution for the problem:

function isPrime(n, div = 2) {
    // input validation
    if (typeof n !== 'number' || n < 2) {
        return false;
    }

    // base cases
    if (n === 2) {
        return true;
    }
    if (n === 1 || n % div === 0) {
        return false;
    }

    // recursive case
    if (div * div > n) {
        return true;
    }

    return isPrime(n, div + 1);
}

This function uses recursion to check if a given number `n` is prime. It starts by checking if `n` is less than 2 or not a positive integer, and if so, it returns false. Then it checks if `n` is 2, which is the only even prime number, and if so, it returns true. It then checks if `n` is divisible by any number from 2 up to the square root of `n`, and if so, it returns false. Otherwise, it calls itself with `n` and `div + 1`, where `div` is incremented by 1 each recursive call.