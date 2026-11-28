const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        const arr1 = lines[1].split(/\s+/).map(Number);
        const arr2 = lines[2].split(/\s+/).map(Number);
        
        let i = n - 1, j = m - 1, k = n + m - 1;
        let res = new Array(k + 1);
        while (i >= 0 && j >= 0) {
            if (arr1[i] > arr2[j]) res[k--] = arr1[i--];
            else res[k--] = arr2[j--];
        }
        while (j >= 0) res[k--] = arr2[j--];
        console.log(res.join(" "));
        rl.close();
    }
});
