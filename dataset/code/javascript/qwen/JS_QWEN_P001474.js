const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, target] = lines[0].split(/\s+/).map(Number);
        const nums = lines[1].split(/\s+/).map(Number);
        
        nums.sort((a,b)=>a-b);
        let res = [];
        for (let i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] === nums[i-1]) continue;
            for (let j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] === nums[j-1]) continue;
                let l = j + 1, r = n - 1;
                while (l < r) {
                    let sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum === target) {
                        res.push(`${nums[i]} ${nums[j]} ${nums[l]} ${nums[r]}`);
                        while (l < r && nums[l] === nums[l+1]) l++;
                        while (l < r && nums[r] === nums[r-1]) r--;
                        l++; r--;
                    } else if (sum < target) l++;
                    else r--;
                }
            }
        }
        console.log(res.join("\n"));
        rl.close();
    }
});
