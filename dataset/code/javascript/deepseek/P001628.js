Here is the JavaScript code:

const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});

let N;
readline.question('', N);

let nums = [];
for(let i = 0; i < N; i++) {
    readline.question('', num);
    nums.push(num);
}

let longest = 0;
let sum = 0;

for(let i = 0; i < N; i++) {
    sum += nums[i];
    if(sum > 0) {
        longest = Math.max(longest, i + 1);
    }
}

console.log(longest);

This code uses the readline module in Node.js to handle input from the user. It first reads the number of elements (N) to be processed from the user. Then it reads each element and adds it to a list. The code then iterates over the list and keeps track of the current sum and the longest prefix whose sum is greater than zero. The longest prefix is then printed to the console.