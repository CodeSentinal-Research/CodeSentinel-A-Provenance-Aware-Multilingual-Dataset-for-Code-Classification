const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    const orig = Math.abs(n);
    let num = orig;
    let rev = 0;
    while(num > 0) {
        rev = rev * 10 + (num % 10);
        num = Math.floor(num / 10);
    }
    console.log(orig === rev ? "Palindrome" : "Not Palindrome");
    rl.close();
});
