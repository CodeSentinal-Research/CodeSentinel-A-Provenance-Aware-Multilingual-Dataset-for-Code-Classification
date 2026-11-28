const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let res = [];
    for(let i=1; i<=n; i++) res.push(i);
    console.log(res.join(" "));
    rl.close();
});
