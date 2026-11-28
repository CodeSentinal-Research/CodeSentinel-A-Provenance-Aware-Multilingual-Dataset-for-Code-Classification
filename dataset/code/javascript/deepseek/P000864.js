Sure, here is the JavaScript solution for the given problem:

function findMissingNumber(nums) {
    let missingNumber = 0;
    for(let i = 0; i < nums.length; i++) {
        missingNumber ^= nums[i];
    }
    return missingNumber;
}
This function takes an array of integers as input. It uses the XOR bitwise operator to find the missing number. The XOR operator is the bitwise equivalent of the OR operator, but it flips the bits in a way that makes it easier to find the missing number. 

For example, if we have the array `[1, 2, 4, 0]`, the XOR operation from left to right is as follows:

1. 1 ^ 2 ^ 4 ^ 0
2. 2 ^ 0 (removes 1 and 4, leaving 2 and 0)
3. 0 ^ 0 (removes both 2 and 0 leaving 0)

The missing number is 0.