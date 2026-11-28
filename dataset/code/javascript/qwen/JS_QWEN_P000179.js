const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const [m, n] = lines[0].split(/\s+/).map(Number);
        const arr1 = lines[1].split(/\s+/).map(Number);
        const arr2 = lines[2].split(/\s+/).map(Number);
        let order = {};
        arr2.forEach((x, i) => order[x] = i);
        let inOrder = arr1.filter(x => order[x] !== undefined).sort((a,b) => order[a]-order[b]);
        let notInOrder = arr1.filter(x => order[x] === undefined).sort((a,b)=>a-b);
        console.log([...inOrder, ...notInOrder].join(" "));
        rl.close();
    }
});
