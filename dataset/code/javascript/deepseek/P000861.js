Here is a JavaScript solution for the problem:

function singleNumber(nums) {
    let num = 0;
    for(let i = 0; i < nums.length; i++) {
        num ^= nums[i];
    }
    return num;
}

In this function, we are using bitwise XOR operator (^). XOR of a number with itself is 0, so we XOR all the elements in the array. The unique number will be the result of the XOR operation.

You can call this function like this:

console.log(singleNumber([1, 2, 3, 2])); // Output: 1

In the above example, the unique number is 1.