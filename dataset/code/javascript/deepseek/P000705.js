Here is the JavaScript code:

function printSubsequences(nums) {
    const output = [];
    const temp = [];
    generateSubsequences(0, nums, temp, output);
    return output;
}

function generateSubsequences(startIndex, nums, temp, output) {
    temp.push(nums[startIndex]);
    output.push(temp.slice());
    for(let i = startIndex + 1; i < nums.length; i++) {
        generateSubsequences(i, nums, temp, output);
        temp.pop();
    }
    temp.pop();
}

console.log(printSubsequences([1, 2, 3]));

This code defines a function `printSubsequences` which generates all possible subsequences of an array. It does this by recursively calling a function `generateSubsequences`, which generates all possible subsequences starting from a given index. The `generateSubsequences` function adds the current number to the subsequence, adds the subsequence to the output, and then recurses on the rest of the array. After each recursive call, it removes the last added number to the subsequence, so it can backtrack and generate all possible subsequences.