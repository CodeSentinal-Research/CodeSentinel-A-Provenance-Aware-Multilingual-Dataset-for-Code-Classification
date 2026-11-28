const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    let sq = n * n;
    let s = n.toString();
    let sqs = sq.toString();
    console.log(sqs.endsWith(s) ? "true" : "false");
    rl.close();
});
