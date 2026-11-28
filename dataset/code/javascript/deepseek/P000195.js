Here is a JavaScript function that will solve the problem:

function rotateArray(inputArray) {
    let rotatedArray = [...inputArray.slice(-1), ...inputArray.slice(0, -1)];
    return rotatedArray;
}

You can use this function by passing your array as an argument. For example:

let array = [1, 2, 3, 4, 5];
console.log(rotateArray(array)); // Outputs: [5, 1, 2, 3, 4]

This function works by using array slicing to create a new array that is a copy of the original array, but with the last element moved to the start of the new array. The original array is then combined with the new array in reverse order to achieve the cyclically rotated effect.