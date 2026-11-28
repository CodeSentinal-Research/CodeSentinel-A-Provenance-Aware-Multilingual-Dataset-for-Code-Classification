Here is the JavaScript code to solve the given problem:

function modularAddition(A, B, M) {
    if (!Number.isInteger(A) || !Number.isInteger(B) || !Number.isInteger(M)) {
        throw new Error('Inputs must be integers');
    }

    if (A < 0 || B < 0 || M < 1 || M > 1000000000000000) {
        throw new Error('Inputs must satisfy 1 <= M <= 10^18, 0 <= A, B <= 10^18');
    }

    return (A + B) % M;
}

This function first checks if the inputs are integers. If not, it throws an error. It then checks if the inputs satisfy the conditions for the problem, and throws another error if they don't. Finally, it calculates and returns the result of the modular addition.