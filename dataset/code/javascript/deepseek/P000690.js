Sure, here's a simple JavaScript function that implements the conversion:

function decToBinary(n) {
    if (n < 1) {
        return n.toString();
    }
    return (decToBinary(Math.floor(n / 2)) + n % 2);
}

The `Math.floor(n / 2)` line takes the integer part of the division. The `n % 2` line takes the remainder of the division (i.e., what's left over when we divide by 2). These two lines are used to 'cut off' the last digit of the binary number, and then we append the last digit to the end of the binary representation of the number that's left.

Test this function with a small input:

console.log(decToBinary(3));  // Outputs: 11

This function works for positive integers only due to the constraint of JavaScript's number type handling.

For larger numbers, you might run into issues with JavaScript's `Number.MAX_SAFE_INTEGER` (2^53 - 1) which is about 9007199254740991. You would need a different approach to convert numbers larger than that.