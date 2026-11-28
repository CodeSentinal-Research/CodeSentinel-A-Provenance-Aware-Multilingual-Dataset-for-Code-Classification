const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const c = input.trim().toLowerCase();
    if(['a','e','i','o','u'].includes(c)) console.log("Vowel");
    else console.log("Consonant");
    rl.close();
});
