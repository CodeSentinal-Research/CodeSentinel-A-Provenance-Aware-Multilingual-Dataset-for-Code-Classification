const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    for(let i=0; i<n; i++) {
        let row = [];
        let c = 1;
        for(let j=0; j<=i; j++) {
            row.push(c);
            c = c * (i - j) / (j + 1);
        }
        console.log(row.join(" "));
    }
    rl.close();
});
