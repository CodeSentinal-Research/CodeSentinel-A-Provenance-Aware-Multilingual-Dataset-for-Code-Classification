Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let N;
rl.question('Enter the number of elements: ', (n) => {
    N = parseInt(n);
    if (isNaN(N) || N < 1 || N > 100000) {
        console.log('Invalid input. Please enter a valid number between 1 and 100000.');
        rl.close();
        return;
    }
    const arr = [];
    rl.setPrompt('Enter element ' + N + ' (or press CTRL+D to end input): ');
    rl.prompt();
    rl.on('line', (line) => {
        if (!line) {
            printLevels();
            rl.close();
            return;
        }
        arr.push(parseInt(line));
        if (arr.length === N) {
            printLevels();
            rl.close();
            return;
        }
    });
});

function printLevels() {
    const levels = [...new Set(arr.filter(a => a))];
    levels.sort((a, b) => a - b);
    levels.forEach((level) => {
        console.log(level);
        const subArr = arr.filter(a => a >= level);
        console.log(...subArr.map(a => `${a}`));
    });
}

This program reads the number of elements N and elements of the heap from the input. It then prints the elements level by level from left to right. The `Set` is used to remove duplicates, and the array is sorted and printed in ascending order.