const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const [m, n] = lines[0].split(/\s+/).map(Number);
        const arr1 = lines[1].split(/\s+/).map(Number);
        const arr2 = lines[2].split(/\s+/).map(Number);
        let s1 = new Set(arr1), s2 = new Set(arr2);
        let inter = [...s1].filter(x => s2.has(x));
        console.log(inter.join(" "));
        rl.close();
    }
});
