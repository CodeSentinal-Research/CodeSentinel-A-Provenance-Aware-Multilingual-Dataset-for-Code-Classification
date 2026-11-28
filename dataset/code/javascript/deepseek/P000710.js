function permute(nums, start = 0) {
    if (start === nums.length - 1) {
        console.log(nums.join(" "));
    } else {
        for (let i = start; i < nums.length; i++) {
            [nums[i], nums[start]] = [nums[start], nums[i]];
            permute(nums, start + 1);
            [nums[i], nums[start]] = [nums[start], nums[i]];  // backtrack
        }
    }
}

function solve(nums) {
    if (nums.length === 0) {
        console.error('Input array cannot be empty');
        return;
    }
    permute(nums);
}

solve([1, 2, 3]);

In this code, `permute` is a recursive function that generates all permutations of the given array. It uses a simple technique for swapping elements.

The `solve` function checks if the input array is empty, and if so, prints an error message. Otherwise, it calls `permute` to generate all permutations of the array.

You can use this code by providing an array of integers as input to the `solve` function. For example, `solve([1, 2, 3])` will print all permutations of the array [1, 2, 3] to the console.