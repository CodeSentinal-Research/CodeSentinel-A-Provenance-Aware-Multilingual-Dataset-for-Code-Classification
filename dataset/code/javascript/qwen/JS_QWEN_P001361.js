const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, target] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let count = 0;
        function subs(i, sum) {
            if(i===n) {
                if(sum===target) count++;
                return;
            }
            subs(i+1, sum+nums[i]);
            subs(i+1, sum);
        }
        subs(0, 0);
        console.log(count);
        rl.close();
    }
});
