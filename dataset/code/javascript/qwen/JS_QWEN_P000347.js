const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [s, kStr] = lines[0].split(/\s+/);
        const k = parseInt(kStr);
        let res = "";
        for(let i=0; i<s.length; i+=2*k) {
            let part = s.substring(i, i+k);
            res += part.split('').reverse().join('') + s.substring(i+k, i+2*k);
        }
        console.log(res);
        rl.close();
    }
});
