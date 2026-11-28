const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let res = [];
        function permute(arr, l, r) {
            if (l === r) res.push(arr.join(" "));
            else {
                for (let i = l; i <= r; i++) {
                    [arr[l], arr[i]] = [arr[i], arr[l]];
                    permute(arr, l + 1, r);
                    [arr[l], arr[i]] = [arr[i], arr[l]];
                }
            }
        }
        permute(arr, 0, n - 1);
        console.log(res.join("\n"));
        rl.close();
    }
});
