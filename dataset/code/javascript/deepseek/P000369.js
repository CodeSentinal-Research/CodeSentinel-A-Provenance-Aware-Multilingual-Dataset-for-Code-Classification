Here is the JavaScript code for your problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the number of strings: ', (N) => {
    let strings = [];
    rl.setPrompt('Enter a string: ');
    for (let i = 0; i < N; i++) {
        rl.prompt();
    }

    rl.close();

    for (let i = 0; i < N; i++) {
        strings.push(rl.line);
    }

    for (let i = 0; i < N; i++) {
        if (strings[i] === '') {
            console.log(i);
            return;
        }
    }

    console.log(-1);
});

In this code, we use the `readline` module to handle the input. We first ask for the number of strings and then for each string. If an empty string is found, we print the index and stop the process. If no empty string is found, we print -1.