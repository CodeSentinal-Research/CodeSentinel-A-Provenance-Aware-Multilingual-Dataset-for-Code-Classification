Sure, here is the JavaScript code for the problem:

function clearKthBit(N, K) {
    // Check if K is within the range of 0 to 31
    if(K >= 0 && K <= 31) {
        return N & ~(1 << K);
    } else {
        throw new Error("K is out of range, it must be between 0 and 31");
    }
}

In this code, we're defining a function `clearKthBit` that takes two arguments: `N` and `K`. `N` is the number we want to modify, and `K` is the position of the bit we want to clear.

We then use the bitwise AND operator (`&`) with a `~` (bitwise NOT) operator, which flips the k-th bit. The `~` operator flips bits, and in the context of JavaScript, the `1 << K` operation shifts 1 bit to the k-th position.

We use a `if` statement to ensure `K` is within the range 0 to 31. If it's not, we throw an error.

This function is then exported and can be used in another file by calling `require('./filename')`.