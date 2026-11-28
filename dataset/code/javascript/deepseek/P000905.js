Here is a simple JavaScript code that calculates the modular subtraction.

function modularSubtraction(A, B, M) {
    if (!Number.isInteger(A) || !Number.isInteger(B) || !Number.isInteger(M)) {
        throw new Error('Inputs must be integers.');
    }
    if (A < 0 || B < 0 || M < 0 || A >= M || B >= M) {
        throw new Error('Inputs must be in the range 0 <= A, B < M.');
    }
    if (Math.abs(A - B) > M) {
        throw new Error('Subtraction result must be in the range 0 <= A-B < M.');
    }
    return A - B % M;
}

This function first checks if the inputs are integers and if they are in the range 0 <= A, B < M. Then, it checks if the subtraction result (A - B) is in the range 0 <= A-B < M. Finally, it returns the modular subtraction result (A - B) mod M.