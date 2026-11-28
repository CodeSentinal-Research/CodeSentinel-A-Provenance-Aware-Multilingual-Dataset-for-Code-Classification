const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        let morse = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."];
        let set = new Set();
        for (let i = 1; i <= n; i++) {
            let trans = "";
            for (let c of lines[i]) trans += morse[c.charCodeAt(0) - 97];
            set.add(trans);
        }
        console.log(set.size);
        rl.close();
    }
});
