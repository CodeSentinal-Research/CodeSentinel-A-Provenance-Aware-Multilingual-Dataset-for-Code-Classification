const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        function isPal(l, r) {
            if (l >= r) return true;
            if (nums[l] !== nums[r]) return false;
            return isPal(l + 1, r - 1);
        }
        console.log(isPal(0, n - 1) ? "true" : "false");
        rl.close();
    }
});
