const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [m, n] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        let miss=1, patches=0, i=0;
        while(miss<=n) {
            if(i<m && nums[i]<=miss) {
                miss+=nums[i++];
            } else {
                miss*=2;
                patches++;
            }
        }
        console.log(patches);
        rl.close();
    }
});
