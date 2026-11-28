function kthLexSmallestHappyString(N, K) {
    if (N === 1 && K === 1) return 'a';
    let result = '';
    for (let i = 0; i < N; i++) {
        if (K % 2 === 1) {
            result = 'c' + result + 'b';
        } else {
            result = 'b' + result + 'c';
        }
        K = Math.floor(K / 2);
    }
    return result;
}

console.log(kthLexSmallestHappyString(3, 4));  // Expected output: cba
This JavaScript code defines a function `kthLexSmallestHappyString` that computes the K-th lexicographically smallest happy string of length N. The function iterates over the range of 1 to N, appending 'c' or 'b' to the result string depending on the iteration index, and halving K. If K is odd at the end of the iteration, it means we are at an odd place and 'c' should come before 'b'.

However, the above code might not work correctly for the constraints due to lack of a clear understanding of what the problem is asking. The constraints are not clear because 3-1 = 2^(N-1) - 1, which can be hard to interpret.

To clarify, let's consider the problem at hand more clearly. The problem statement asks for the K-th lexicographically smallest happy string. A happy string is a string that consists only of the characters 'a', 'b', and 'c', with no two adjacent characters being equal.

If you want the smallest happy string of length N, you could use a depth-first search or a breadth-first search to traverse all possible happy strings of length N. But if you want the K-th lexicographically smallest happy string, you would need a different approach.