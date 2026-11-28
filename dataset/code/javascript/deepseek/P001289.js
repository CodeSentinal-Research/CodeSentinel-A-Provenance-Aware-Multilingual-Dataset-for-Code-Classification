Here is a JavaScript solution for the problem:

let input = require('fs').readFileSync('/dev/stdin', 'utf8');
let [N, ...arr] = input.split('\n').map(Number);

arr.sort((a, b) => b - a);

let minSum = Number.MAX_SAFE_INTEGER;

for (let i = 0; i < N; i += 2) {
    let sum = arr[i] + arr[i + 1];
    minSum = Math.min(minSum, sum);
}

console.log(minSum);

In this code:
- We first read the input from stdin.
- We split the input string into an array of numbers.
- We sort the array in descending order.
- We initialize a variable minSum to a large number (MAX_SAFE_INTEGER in JavaScript).
- We then loop through the array, pairing the smallest pair and adding them to minSum.
- Finally, we print the minimized maximum pair sum.