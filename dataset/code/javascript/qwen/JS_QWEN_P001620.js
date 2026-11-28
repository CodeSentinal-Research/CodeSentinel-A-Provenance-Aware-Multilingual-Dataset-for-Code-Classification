const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2 + parseInt(lines[2])) {
        const n = parseInt(lines[0]);
        const nums = lines[1].split(/\s+/).map(Number);
        const q = parseInt(lines[2]);
        
        let evenPrefix = [0];
        let oddPrefix = [0];
        for (let i = 0; i < n; i++) {
            evenPrefix.push(evenPrefix[evenPrefix.length - 1] + (i % 2 === 0 ? nums[i] : 0));
            oddPrefix.push(oddPrefix[oddPrefix.length - 1] + (i % 2 !== 0 ? nums[i] : 0));
        }
        
        let res = [];
        for (let i = 3; i < 3 + q; i++) {
            const [l, r] = lines[i].split(/\s+/).map(Number);
            // Sum of elements at even positions relative to start of array? 
            // Problem says "alternate positions... starting from left endpoint"
            // So if L is even index, we want even indices in [L,R]. If L is odd, we want odd indices.
            let sum = 0;
            if (l % 2 === 0) {
                sum = evenPrefix[r + 1] - evenPrefix[l];
            } else {
                sum = oddPrefix[r + 1] - oddPrefix[l];
            }
            res.push(sum);
        }
        console.log(res.join("\n"));
        rl.close();
    }
});
