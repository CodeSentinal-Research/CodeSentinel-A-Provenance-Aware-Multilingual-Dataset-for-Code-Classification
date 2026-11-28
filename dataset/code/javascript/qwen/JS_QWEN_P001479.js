const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let sorted = [...nums].sort((a,b)=>a-b);
        let start = 0, end = n - 1;
        while (start < n && nums[start] === sorted[start]) start++;
        while (end >= 0 && nums[end] === sorted[end]) end--;
        
        console.log(start > end ? 0 : end - start + 1);
        rl.close();
    }
});
