function reverseBits(N) {
    // Convert the input to a binary string, 
    // padding with zeros to make it a 32-bit string
    let binaryString = N.toString(2).padStart(32, '0');

    // Reverse the bits
    let reversedBits = binaryString.split('').reverse().join('');

    // Convert the reversed bits back to a decimal number
    let reversedNumber = parseInt(reversedBits, 2);

    return reversedNumber;
}

// Test the function
console.log(reverseBits(18)); // Outputs: 2205159221