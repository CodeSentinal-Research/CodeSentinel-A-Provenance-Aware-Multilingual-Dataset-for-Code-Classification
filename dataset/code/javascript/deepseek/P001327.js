Here's the JavaScript code that will solve the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let numbers = [];

rl.question('Enter the number of elements: ', (n) => {
    rl.question('Enter the elements: ', (inputs) => {
        numbers = inputs.split(' ').map(Number);
        findSubsets(0, [], []);
        rl.close();
    });
});

function findSubsets(index, current, output) {
    if (output.length > 0) {
        console.log(output.join(", "));
    }
    for (let i = index; i < numbers.length; i++) {
        findSubsets(i + 1, current.concat(numbers[i]), output.concat(numbers[i]));
    }
    findSubsets(index + 1, current, output);
}

In this code, we use the readline module to read the input from the user. We ask for the number of elements, and then for the elements themselves. After that, we call the findSubsets function with the first index (0) and an empty current and output array.

The findSubsets function then checks if the output array is not empty. If it is, it prints the output array.

Then for each index, we add one to the current index and add the current number to the output array.

After that, we call the function again, this time with the current index plus one and the current array and the output array.

This code will handle input from the user and print all unique subsets of the given integers.