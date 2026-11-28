const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        const target = parseInt(lines[2]);
        function findSub(i, sum, curr) {
            if (sum === target) {
                console.log(curr.join(" "));
                return true;
            }
            if (i === n || sum > target) return false;
            if (findSub(i + 1, sum + arr[i], [...curr, arr[i]])) return true;
            return findSub(i + 1, sum, curr);
        }
        if (!findSub(0, 0, [])) console.log(-1);
        rl.close();
    }
});
