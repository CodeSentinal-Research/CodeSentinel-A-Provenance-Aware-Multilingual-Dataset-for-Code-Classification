Here is the JavaScript solution for the given problem:

function subsets(nums) {
    var result = [];
    var subset = [];
    nums.sort((a, b) => a - b); // sort the array in lexicographical order
    generateSubsets(0, nums, subset, result);
    return result;
}

function generateSubsets(startIndex, nums, subset, result) {
    result.push(subset.slice()); // copy the subset to result
    for(let i = startIndex; i < nums.length; i++) {
        if(i > startIndex && nums[i] === nums[i-1]) continue; // skip duplicates
        subset.push(nums[i]);
        generateSubsets(i + 1, nums, subset, result);
        subset.pop();
    }
}

// test
var nums = [1,2,2];
console.log(subsets(nums));

In this solution, the function `subsets(nums)` is the main function to generate all unique subsets of the given array. It first sorts the array in lexicographical order. Then, it calls the `generateSubsets(0, nums, subset, result)` function to start generating subsets.

The `generateSubsets(startIndex, nums, subset, result)` function is the recursive function to generate all subsets. It first adds the current subset to the result. Then, it loops through the rest of the array. If the current number is the same as the previous one, it skips this iteration, because a number cannot be included in a subset twice. If not, it adds the current number to the subset, generates all subsets by calling itself recursively, and removes the last element from the subset to backtrack.