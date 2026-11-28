const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let res = [];
        function genSub(arr, curr, i) {
            if (i === arr.length) {
                if (curr.length > 0) res.push(curr.join(" "));
                return;
            }
            genSub(arr, curr, i + 1);
            genSub(arr, [...curr, arr[i]], i + 1);
        }
        genSub(arr, [], 0);
        console.log(res.join("\n"));
        rl.close();
    }
});
