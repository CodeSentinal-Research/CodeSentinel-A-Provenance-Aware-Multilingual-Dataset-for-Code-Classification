Here's the JavaScript code that solves the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the number of elements: ', (n) => {
    rl.question('Enter elements: ', (input) => {
        const arr = input.split(' ').map(Number);
        const oddOccurrences = arr.filter(item => arr.indexOf(item) % 2 === 1);
        if (oddOccurrences.length === 2) {
            console.log(`The two elements with odd occurrence are ${oddOccurrences[0]} and ${oddOccurrences[1]}`);
        } else {
            console.log('No such pair of elements exist');
        }
        rl.close();
    });
});

This code uses the readline module to read input from the user. The first line reads the number of elements, and the second line reads the elements themselves. Then, it filters the array to find the elements that occur odd number of times in the array. If there are exactly two elements that occur odd number of times, it prints them out. Otherwise, it prints a message saying that no such pair of elements exist.