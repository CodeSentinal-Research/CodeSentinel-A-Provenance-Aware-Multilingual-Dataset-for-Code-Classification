const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const [n, m, success] = lines[0].split(/\s+/).map(Number);
        const spells = lines[1].split(/\s+/).map(Number);
        const potions = lines[2].split(/\s+/).map(Number);
        
        potions.sort((a, b) => a - b);
        
        let res = [];
        for (let spell of spells) {
            let target = Math.ceil(success / spell);
            let left = 0, right = m;
            while (left < right) {
                let mid = Math.floor((left + right) / 2);
                if (potions[mid] < target) left = mid + 1;
                else right = mid;
            }
            res.push(m - left);
        }
        
        console.log(res.join(" "));
        rl.close();
    }
});
