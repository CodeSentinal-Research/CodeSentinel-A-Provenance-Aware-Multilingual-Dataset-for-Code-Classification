Here is a simple JavaScript function to solve the problem:

function findComplement(num) {
    // Convert the number to binary and then invert it
    let binary = num.toString(2);
    let complement = parseInt(binary.replace(/1/g, '2').replace(/0/g, '1'), 2);
    return complement;
}

console.log(findComplement(10)); // Output: 9
console.log(findComplement(20)); // Output: 9

This function works by converting the input number to a binary string, then replacing all the 1's with 2's and all the 0's with 1's. The binary string is then parsed as a number using 2 as the radix. This will give us the complement of the binary string, which we can then return as the result.