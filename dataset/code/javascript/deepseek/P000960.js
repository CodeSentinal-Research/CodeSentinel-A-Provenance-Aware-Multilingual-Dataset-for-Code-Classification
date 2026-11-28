Sure, here is the JavaScript code that handles the problem:

function findDiophantineSolution(A, B, C) {
    let min = Math.min(A, B, C);
    if (min > Math.max(A, B, C)) {
        return -1;
    }
    for (let X = min; X <= C; X++) {
        let Y = (C - X) / B;
        if (X * A + Y * B === C) {
            return [X, Y];
        }
    }
    return -1;
}

This function works by first finding the smallest integer that is greater than the largest one and less than the sum of the other two. It then iterates from the smallest integer to the largest one, trying to find a pair of integers such that AX + BY equals to C. If it finds such a pair, it returns it as an array. If no such pair is found, it returns -1.

This function assumes that A, B and C are integers and handles the problem by checking if a solution exists.

NOTE: This function is based on the theory that if AX + BY = C, then Y must be a fraction of C-X. If A is greater than B, then the difference must be even smaller than C, otherwise it's impossible for B to be larger than C, so Y is always smaller than X.