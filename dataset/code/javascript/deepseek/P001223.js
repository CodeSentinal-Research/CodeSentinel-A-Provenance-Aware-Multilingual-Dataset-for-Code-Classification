Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the length of the string: ', (n) => {
    rl.close();
    console.log(countStrings(n));
});

function countStrings(n) {
    if (n === 0) return 1;
    if (n === 1) return 2;

    let count = [1, 2];
    for (let i = 2; i < n; i++) {
        let newCount = count[0] + count[1];
        count[0] = count[1];
        count[1] = newCount;
    }
    return count[1];
}

This program uses a dynamic programming approach to solve the problem. It first initializes two variables, `count[0]` and `count[1]`, to the base cases. Then, it fills up the array with the dynamic programming values using a loop. For each iteration, it calculates the new count by adding the count for the previous two strings and assigns it to `count[1]`. It then updates `count[0]` to `count[1]` for the next iteration.