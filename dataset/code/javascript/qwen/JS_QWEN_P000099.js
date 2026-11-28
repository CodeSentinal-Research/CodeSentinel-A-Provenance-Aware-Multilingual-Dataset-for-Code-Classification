const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let c = 1;
    for(let i=1; i<=n; i++) {
        let row = [];
        for(let j=1; j<=i; j++) row.push(c++);
        console.log(row.join(" "));
    }
    rl.close();
});
