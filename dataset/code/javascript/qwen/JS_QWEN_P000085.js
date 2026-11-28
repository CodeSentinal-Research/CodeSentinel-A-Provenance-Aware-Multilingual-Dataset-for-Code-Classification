const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const m = parseInt(input.trim());
    if(m >= 90) console.log("A");
    else if(m >= 80) console.log("B");
    else if(m >= 70) console.log("C");
    else if(m >= 60) console.log("D");
    else console.log("F");
    rl.close();
});
