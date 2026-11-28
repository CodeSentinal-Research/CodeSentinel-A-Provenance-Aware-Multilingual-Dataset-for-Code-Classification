const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let prefix = [0];
    for (let c of s) {
        prefix.push(prefix[prefix.length - 1] + (c.charCodeAt(0) - 96));
    }
    console.log(prefix.slice(1).join(" "));
    rl.close();
});
