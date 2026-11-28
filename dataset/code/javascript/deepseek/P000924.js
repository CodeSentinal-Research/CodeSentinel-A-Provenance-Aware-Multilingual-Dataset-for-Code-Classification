function decimalToBinary(n) {
    if (n < 0 || n > 2**63 - 1) {
        throw new Error('Input must be in the range of 0 to 2^63 - 1');
    }
    return n.toString(2);
}