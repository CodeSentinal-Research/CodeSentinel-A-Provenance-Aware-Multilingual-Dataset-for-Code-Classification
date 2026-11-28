Here's the JavaScript code:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the count of numbers: ', (n) => {
    rl.question('Enter the numbers: ', (numbers) => {
        const nums = numbers.split(' ').map(Number);
        const numSet = new Set();
        let duplicate;
        for(let num of nums) {
            if (numSet.has(num)) {
                duplicate = num;
                break;
            }
            numSet.add(num);
        }
        console.log(duplicate);
        rl.close();
    });
});

This program reads the count of numbers and the numbers from the user, and then finds the duplicate number. It uses a Set to store the numbers as it iterates through them. If a number is already in the Set, it is a duplicate and it will immediately stop.