const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let totalOnes = nums.filter(x => x === 1).length;
        if (totalOnes === 0) { console.log(0); rl.close(); return; }
        
        let minSwaps = Infinity;
        let currentOnes = 0;
        
        // Initial window
        for (let i = 0; i < totalOnes; i++) {
            if (nums[i] === 1) currentOnes++;
        }
        minSwaps = totalOnes - currentOnes;
        
        // Slide window
        for (let i = totalOnes; i < n; i++) {
            if (nums[i] === 1) currentOnes++;
            if (nums[i - totalOnes] === 1) currentOnes--;
            minSwaps = Math.min(minSwaps, totalOnes - currentOnes);
        }
        
        console.log(minSwaps);
        rl.close();
    }
});
