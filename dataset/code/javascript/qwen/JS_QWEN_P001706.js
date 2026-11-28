const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let res = [];
        function genSub(i, curr) {
            if (i === n) {
                if (curr.length > 0) res.push(curr.join(" "));
                return;
            }
            genSub(i + 1, curr);
            genSub(i + 1, [...curr, nums[i]]);
        }
        genSub(0, []);
        console.log(res.join("\n"));
        rl.close();
    }
});
