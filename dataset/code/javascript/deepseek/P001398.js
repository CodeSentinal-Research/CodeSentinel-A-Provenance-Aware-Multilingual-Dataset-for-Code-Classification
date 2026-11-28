Here is the JavaScript code for your problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter number of strings: ', (n) => {
    let strings = [];
    rl.setPrompt('Enter a string: ');

    for(let i = 0; i < n; i++) {
        rl.prompt();
    }

    rl.close();

    strings.push(rl.line);

    let commonChars = findCommonChars(strings);

    console.log(commonChars);

    process.exit();
});

function findCommonChars(strings) {
    let chars = strings[0].split('');

    strings.slice(1).forEach(str => {
        chars = chars.filter(c => str.includes(c));
    });

    return chars.sort();
}

This code uses the readline module to read the input from the user, which is necessary because JavaScript doesn't have built-in support for reading from the command line. The code first asks the user for the number of strings, then reads in each string, and finally finds and prints the common characters.