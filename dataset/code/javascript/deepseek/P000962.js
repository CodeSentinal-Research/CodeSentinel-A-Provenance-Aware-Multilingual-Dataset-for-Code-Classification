Here is the JavaScript code for the Frobenius Coin Problem:

function solveFrobeniusCoinProblem(A, B) {
    // Check if A and B are positive integers and coprime
    if (A < 1 || B < 1 || !isCoprime(A, B)) {
        throw new Error('A and B should be positive integers and coprime');
    }

    // Initialize the largest number
    let largest = A * B;

    // Iterate over all possible values of X and Y
    for (let X = 0; X <= A; X++) {
        for (let Y = 0; Y <= B; Y++) {
            // Calculate the current largest number
            let current = A * X + B * Y;
            if (current > largest) {
                largest = current;
            }
        }
    }

    return largest;
}

function isCoprime(a, b) {
    // Check if a and b are both even
    if ((a % 2 === 0) && (b % 2 === 0)) {
        return false;
    }

    // Check if one is even and the other is odd
    if ((a % 2 === 1) && (b % 2 === 1)) {
        return false;
    }

    // If we've made it here, a and b are coprime
    return true;
}

This code works by iterating over all possible combinations of X and Y, and checking if the current largest number is less than the current largest number. If it is, it updates the largest number.

The `isCoprime` function checks if two integers are coprime by checking if one is even and the other is odd. It also checks if both are even by checking if one is odd and the other is even. If they are both either, or both are odd, they are not coprime.