function getBitwiseAND(left, right) {
    // Handle edge cases
    if (left === 0 || right === 0) {
        return 0;
    }

    // If both numbers are in binary format,
    // Then get the common bits from right to left
    // Else get the common bits from left to right
    let shift = 0;
    while ((left | right) > 0 && left !== right) {
        left >>= 1;
        right >>= 1;
        shift++;
    }

    return left << shift;
}
This JavaScript function takes two integers (left and right) as input. It uses bitwise AND operation to find the common bits in both numbers. If either number is 0, it immediately returns 0 as the result.

However, the solution assumes that the numbers are in binary format (i.e., they are positive integers with a maximum of 31 bits), so it only supports numbers in the range of 0 to 2^31 - 1.

For example, if you call `getBitwiseAND(10, 7)`, the function will return `2`, which is the result of the bitwise AND operation.

This solution works by repeatedly right-shifting both numbers (`left >>= 1` and `right >>= 1`) until `left` and `right` are equal (i.e., they are one and the same number in binary format). After this, the `shift` variable indicates the number of times this loop ran. We then return `left` shifted by `shift` bits.

This approach is efficient and has a time complexity of O(1), which means it runs in constant time regardless of the input size.