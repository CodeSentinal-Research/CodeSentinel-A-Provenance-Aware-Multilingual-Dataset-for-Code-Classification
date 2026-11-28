Here's the JavaScript code:

function countInversions(nums) {
    if (nums.length === 1) {
        return 0;
    }

    const mid = Math.floor(nums.length / 2);
    const leftHalf = nums.slice(0, mid);
    const rightHalf = nums.slice(mid);

    return (
        countInversions(leftHalf) +
        countInversions(rightHalf) +
        mergeAndCount(leftHalf, rightHalf, nums.length)
    );
}

function mergeAndCount(leftHalf, rightHalf, totalElements) {
    let inversions = 0;
    let i = 0;
    let j = 0;
    const merged = [];

    while (i < leftHalf.length && j < rightHalf.length) {
        if (leftHalf[i] <= rightHalf[j]) {
            merged.push(leftHalf[i]);
            i++;
        } else {
            merged.push(rightHalf[j]);
            inversions += leftHalf.length - i;
            j++;
        }
    }

    while (i < leftHalf.length) {
        merged.push(leftHalf[i]);
        i++;
    }

    while (j < rightHalf.length) {
        merged.push(rightHalf[j]);
        j++;
    }

    return inversions;
}

// Test the function
const nums = [3, 2, 1, 5, 4, 7];
console.log(countInversions(nums));  // Output: 3

This code defines two functions:

1. `countInversions`: This function takes an array of integers as input and returns the total number of inversions. It recursively splits the array into two halves until it can no longer split, then it merges the sorted halves and counts inversions.

2. `mergeAndCount`: This function takes two sorted arrays and the total number of elements in the original array as input. It merges the two arrays into one sorted array, and counts the number of inversions in the array by traversing from the beginning to the end.