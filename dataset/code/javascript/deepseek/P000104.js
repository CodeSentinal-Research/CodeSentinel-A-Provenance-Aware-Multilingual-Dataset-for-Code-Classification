Here is the JavaScript code for your problem:

var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var N = Number(input.split('\n')[0]);
var array = input.split('\n')[1].split(' ').map(Number);
var sum = array.reduce((a, b) => a + b, 0);
var average = sum / N;
console.log(average.toFixed(1));

In this code, we first read the number of elements N from the first line of the input. Then, we split the second line into an array of numbers and map each number into a number. Finally, we calculate the sum of all numbers and divide it by N to get the average. We then log the average to the console.