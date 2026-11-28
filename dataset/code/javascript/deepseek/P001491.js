Here's the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let cases = Number(rl.readline());
rl.close();

for(let i = 0; i < cases; i++) {
    let input = rl.readline().split(' ').map(Number);
    let scores = input[0];
    let k = input[1];
    let scoresArr = input.slice(2);

    scoresArr.sort(function(a, b){return a - b});
    
    console.log(Math.min(...scoresArr.slice(scores - k, scores)));
}

In this code, we first read the number of test cases from the standard input. Then, for each case, we read the number of scores and the scores themselves. After sorting the scores array in ascending order, we print the minimum score difference among the `scores - k` highest scores.

Please note that we are not using `Math.min` here because it is a built-in JavaScript function, not a function for this problem. The `...` syntax is used to spread the array elements into a new array. This is how we can pass the array of scores to the `Math.min` function.