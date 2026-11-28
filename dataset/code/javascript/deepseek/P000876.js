function findComplement(num) {
    // Convert num to binary
    let binary = num.toString(2);
    // Flip the binary digits
    let complement = '';
    for (let i = 0; i < binary.length; i++) {
        complement += binary[i] === '0' ? '1' : '0';
    }
    // Convert the complement from binary to decimal
    return parseInt(complement, 2);
}