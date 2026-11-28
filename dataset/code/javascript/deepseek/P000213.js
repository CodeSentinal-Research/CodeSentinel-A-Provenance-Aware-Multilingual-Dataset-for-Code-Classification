function thirdMax(nums) {
    let numsSet = new Set(nums);
    let numsArray = Array.from(numsSet);

    if (numsArray.length < 3) {
        return Math.max(...numsArray);
    }

    numsArray.sort((a, b) => b - a);

    return numsArray[2];
}

// Example usage:
let nums = [1, 2, 3, 4, 5];
console.log(thirdMax(nums)); // Output: 4
This JavaScript function first transforms the input array into a Set, which removes all duplicate values because we're finding the third distinct maximum number. After that, it converts the Set back to an array. If there are less than 3 unique numbers, it returns the maximum value from the array. Otherwise, it sorts the array in descending order and returns the third element.