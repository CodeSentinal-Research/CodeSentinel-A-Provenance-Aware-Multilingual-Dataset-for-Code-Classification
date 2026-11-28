Here is the JavaScript code to solve the problem:

let [allowed, n, ...words] = require('fs').readFileSync(0).toString().split('\n');

let count = words.reduce((count, word) => {
    if (word.split('').every(c => allowed.includes(c))) count++;
    return count;
}, 0);

console.log(count);

This code reads the input from the standard input (`0` is the file descriptor of the standard input). The allowed string and the number of words are split into separate variables. The `every` function is used to check if all characters in a word are allowed. If they are, the counter is incremented. The final count is then printed to the standard output.