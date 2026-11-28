Here is the JavaScript code to find the two unique elements that appear once and every other element appears twice:

function findSingle(nums) {
    let diff = 0;
    for(let i = 0; i < nums.length; i++){
        diff ^= nums[i];
    }
    let pos = diff & -diff; //bitwise AND operation with itself and negative of diff

    let num1 = 0, num2 = 0;
    for(let i = 0; i < nums.length; i++){
        if(nums[i] & pos) num1 ^= nums[i];
        else num2 ^= nums[i];
    }
    return [num1, num2];
}
This code works by first finding the xor of all numbers (using bitwise XOR operation), then find the smallest set bit in the xor result. After that, separate all numbers into two groups based on the bit set in the smallest set bit. In the end, return the two unique numbers.

Please note that in JavaScript, we can't handle multidimensional array as input as JavaScript function can't handle multidimensional arrays directly. So, if you're using this function, you should pass a one dimensional array as the input. If you need to handle multidimensional arrays, you should convert it to a one dimensional array before you pass it to the function.