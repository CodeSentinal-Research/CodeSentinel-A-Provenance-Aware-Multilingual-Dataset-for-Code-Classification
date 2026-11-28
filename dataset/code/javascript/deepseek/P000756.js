Here is the JavaScript code for your problem:

function quickSort(nums) {
    if (nums.length < 2) {
        return nums;
    }

    const pivot = nums[0];

    const lower = [];
    const higher = [];

    for (let i = 1; i < nums.length; i++) {
        if (nums[i] < pivot) {
            lower.push(nums[i]);
        } else {
            higher.push(nums[i]);
        }
    }

    return quickSort(lower).concat(pivot, quickSort(higher));
}

To handle the input, you can use a function like this:

const nums = [9, 7, 5, 11, 12, 2, 14, 3, 10, 6];
const sortedNums = quickSort(nums);
console.log(sortedNums);

This will print the sorted array to the console.

This code works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot. The sub-arrays are then recursively sorted.