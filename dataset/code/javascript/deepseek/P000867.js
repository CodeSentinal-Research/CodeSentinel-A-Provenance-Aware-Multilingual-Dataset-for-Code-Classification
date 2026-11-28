Here is the JavaScript code:

function hammingDistance(x, y) {
    var xor = x ^ y;
    var distance = 0;
    while (xor) {
        distance += xor & 1;
        xor >>= 1;
    }
    return distance;
}

In this function, `x ^ y` is used to get the XOR of the two numbers, which is the binary representation of the Hamming distance. The `while` loop counts the number of set bits in the XOR result and increment `distance` by 1. The loop continues until `xor` is 0. The `distance` is returned as the result.