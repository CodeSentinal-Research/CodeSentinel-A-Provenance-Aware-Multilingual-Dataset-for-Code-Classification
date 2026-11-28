const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let count = {};
    for (let c of s) count[c] = (count[c] || 0) + 1;
    
    let chars = Object.keys(count).sort();
    chars.sort((a, b) => count[b] - count[a] || a.charCodeAt(0) - b.charCodeAt(0));
    
    let res = "";
    for (let c of chars) {
        res += c.repeat(count[c]);
    }
    console.log(res);
    rl.close();
});
