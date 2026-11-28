const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        nums.sort((a,b)=>a-b);
        let sum = nums.reduce((a,b)=>a+b, 0);
        
        for(let i=0; i<k; i++) {
            if(nums[0]<0) {
                sum -= 2*nums[0];
                nums[0] = -nums[0];
                nums.sort((a,b)=>a-b);
            } else break;
        }
        if(k%2!==0 && nums[0]>0) sum -= 2*nums[0];
        console.log(sum);
        rl.close();
    }
});
