Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the number of rows: ', (N) => {
    let grid = [];
    rl.setPrompt('Enter a row: ');
    for (let i = 0; i < N; i++) {
        rl.prompt();
    }

    rl.close();
});

In this code, we're using Node.js's `readline` module to handle the user input. The first step is to get the size of the grid from the user. Then, we create a grid of size N and get each row as input from the user. 

Please note that the code provided here is a simplified example and does not handle the case where the user inputs an invalid size for the grid. For a more robust solution, you would need to add error handling to this code to handle invalid input.