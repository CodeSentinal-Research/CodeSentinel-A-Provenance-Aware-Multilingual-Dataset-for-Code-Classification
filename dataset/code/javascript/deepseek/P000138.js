Here is the JavaScript code that merges two sorted integer arrays into one sorted array:

// Read the array length
let m = parseInt(readline());
let n = parseInt(readline());

// Read the first array
let arr1 = readline().split(' ').map(Number).sort((a, b) => a - b);

// Read the second array
let arr2 = readline().split(' ').map(Number).sort((a, b) => a - b);

let i = 0, j = 0;
let merged = [];

while (i < m && j < n) {
    if (arr1[i] < arr2[j]) {
        merged.push(arr1[i]);
        i++;
    } else {
        merged.push(arr2[j]);
        j++;
    }
}

while (i < m) {
    merged.push(arr1[i]);
    i++;
}

while (j < n) {
    merged.push(arr2[j]);
    j++;
}

console.log(merged.join(' '));

This code reads the array lengths and the arrays from the input, then merges them into a sorted array. The `parseInt` function is used to convert the input into a number, and the `readline` function is used to read a line of input. The `.split(' ')` method is used to split the input into an array, and the `.map(Number).sort((a, b) => a - b)` method is used to convert the input into a number array and sort it. The `while` loop is used to merge the two arrays into one sorted array. The `console.log` function is used to print the merged array.