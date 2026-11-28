const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, first] = lines[0].split(/\s+/).map(Number);
        const encoded = lines[1].split(/\s+/).map(Number);
        let res = [first];
        for (let i = 0; i < n; i++) {
            res.push(res[res.length-1] ^ encoded[i]);
        }
        console.log(res.join(" "));
        rl.close();
    }
});
