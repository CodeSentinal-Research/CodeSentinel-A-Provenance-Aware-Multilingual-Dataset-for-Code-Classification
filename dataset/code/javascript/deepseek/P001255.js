Here is the JavaScript code for the problem. The code reads the input string, then checks each character in the string. If the character is ')', it increments a count of unmatched parentheses. If the count of unmatched parentheses is even, it adds 2 to the count of parentheses to be added.

let readline = require('readline');

let rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter a string: ', function(input) {
    let parentheses = 0;
    let unmatched = 0;
    for(let i = 0; i < input.length; i++) {
        if (input[i] === '(') {
            parentheses++;
        } else if (parentheses > 0) {
            parentheses--;
            unmatched++;
        }
    }
    console.log(unmatched);
    rl.close();
});

The code will read a string from the console, calculate the minimum number of parentheses that must be added, and print the result. The input is expected to be a single string.