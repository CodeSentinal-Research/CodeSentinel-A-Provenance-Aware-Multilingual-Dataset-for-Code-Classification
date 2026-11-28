const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let product = 1;
        for (let i = 0; i < k; i++) product *= nums[i];
        
        let maxProd = product;
        
        for (let i = k; i < n; i++) {
            product = (product / nums[i - k]) * nums[i];
            maxProd = Math.max(maxProd, product);
        }
        
        console.log(maxProd);
        rl.close();
    }
});
