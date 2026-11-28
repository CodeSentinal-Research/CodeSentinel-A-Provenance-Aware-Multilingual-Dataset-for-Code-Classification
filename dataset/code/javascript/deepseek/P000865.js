Here is the JavaScript code for the problem:

function xor(nums) {
    let xorVal = 0;
    for(let i = 0; i < nums.length; i++) {
        xorVal ^= nums[i];
    }
    return xorVal;
}

console.log(xor([1, 2, 3, 4, 5]));
This code will take an array of integers as input and will return the XOR of all the elements in the array. The XOR operator ^ is used to find the XOR of two numbers. The XOR of all numbers in an array is calculated by iterating through the array and performing the XOR operation on each element.