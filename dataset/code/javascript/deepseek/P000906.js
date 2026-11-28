Here's the JavaScript code to solve the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter A: ', (A) => {
    rl.question('Enter B: ', (B) => {
        rl.question('Enter M: ', (M) => {
            const result = (A * B) % M;
            console.log(result);
            rl.close();
        });
    });
});

This program uses the Readline module in Node.js to read the user input. The `readline.createInterface` function creates an interface that reads from and writes to the console. The user is then asked to input three numbers: A, B, and M. The multiplication of A and B is done mod M, and the result is then printed to the console.

Please note that this code assumes that the input numbers are integers and that they are within the given constraints (1 <= M <= 10^18, 0 <= A, B <= 10^18). If you provide input outside of these constraints, the code may produce incorrect results.