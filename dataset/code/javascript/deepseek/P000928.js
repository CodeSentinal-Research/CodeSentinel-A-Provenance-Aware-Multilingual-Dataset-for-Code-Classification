Here is the code snippet for the problem:

function addBinary(A, B) {
    let carry = 0;
    let result = '';

    // Iterate from rightmost-most digits
    for (let i = A.length - 1; i >= 0; i--) {
        let sum = ((A[i] === '1') ? 1 : 0) + ((B[i] === '1') ? 1 : 0) + carry;
        result = ('1' + result); // prepend sum to result
        carry = sum > 1 ? 1 : 0; // update carry
        sum = sum > 1 ? sum - 2 : sum; // update sum
        if(sum === 0) break;
    }

    // If there is still a carry left, append it to result
    if(carry === 1) result = '1' + result;

    return result;
}

This JavaScript function uses a pointer approach to iterate from rightmost-most digits of both input binary strings A and B. For each digit in the binary strings, it adds the corresponding digits from A and B, along with the carry from the previous addition. The sum is then updated as follows: if the sum is greater than 1, it subtracts 2 from the sum; if the sum is 0, it breaks the loop (as the loop will eventually end with the result being empty, and thus the carry and result would not be updated in subsequent iterations). After adding all the digits, if there is still a carry left, it appends it to the result string (prepended by '1').

The function takes binary strings A and B as inputs and returns their sum as a binary string. The constraints for the inputs are already taken into account: they are binary strings with length between 1 and 10^5, and they only contain the characters '0' and '1'.