Here is the JavaScript solution for the problem:

function selectionSortRecursive(nums) {
    if (nums.length === 1) {
        return nums;
    }

    let minIndex = 0;
    for (let i = 1; i < nums.length; i++) {
        if (nums[i] < nums[minIndex]) {
            minIndex = i;
        }
    }

    let temp = nums[0];
    nums[0] = nums[minIndex];
    nums[minIndex] = temp;

    nums.length = 1;

    return selectionSortRecursive(nums);
}

This function takes an array of integers as input and recursively sorts it using the Selection Sort algorithm. The selection sort algorithm works by repeatedly finding the minimum element from the unsorted part and putting it at the beginning. The time complexity of this solution is O(n^2) due to the two nested loops.

This function also does not handle the input validation as it is assumed that the input will always be an array of integers.

To use this function, you can call it with your array as follows:

let sortedArray = selectionSortRecursive([64, 34, 25, 12, 22, 11, 90]);
console.log(sortedArray);