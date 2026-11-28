const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        const arr1 = lines[1].split(/\s+/).map(Number);
        const arr2 = lines[2].split(/\s+/).map(Number);
        
        let res = [];
        let i = 0, j = 0;
        while (i < n && j < m) {
            if (arr1[i] <= arr2[j]) res.push(arr1[i++]);
            else res.push(arr2[j++]);
        }
        while (i < n) res.push(arr1[i++]);
        while (j < m) res.push(arr2[j++]);
        console.log(res.join(" "));
        rl.close();
    }
});
