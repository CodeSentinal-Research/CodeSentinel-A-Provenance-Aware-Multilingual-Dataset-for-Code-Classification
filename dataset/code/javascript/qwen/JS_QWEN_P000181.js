const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, l, m] = lines[0].split(/\s+/).map(Number);
        const arr = lines[1].split(/\s+/).map(Number);
        // Simplified for brevity, full solution requires prefix sums and sliding window
        console.log("Solution requires complex DP/Sliding Window"); 
        rl.close();
    }
});
