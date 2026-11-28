Sure, here is the JavaScript code for your problem.

let n = parseInt(readline());
let arr = readline().split(' ').map(Number).filter(Boolean);
let negatives = arr.filter(num => num < 0);
arr = arr.filter(num => num >= 0);
let result = arr.concat(negatives);
console.log(result.join(' '));

This code will read the size of the array, the elements of the array, and then print the modified array. It will filter out the negative numbers and put the remaining positive numbers in the array.