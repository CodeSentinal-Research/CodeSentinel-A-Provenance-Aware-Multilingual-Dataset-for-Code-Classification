const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const fruits = lines[1].split(/\s+/).map(Number);
        
        let basket = {};
        let maxFruits = 0;
        let left = 0;
        
        for (let right = 0; right < n; right++) {
            basket[fruits[right]] = (basket[fruits[right]] || 0) + 1;
            
            while (Object.keys(basket).length > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] === 0) delete basket[fruits[left]];
                left++;
            }
            
            maxFruits = Math.max(maxFruits, right - left + 1);
        }
        
        console.log(maxFruits);
        rl.close();
    }
});
