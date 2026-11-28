const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 4) {
        const n1 = parseInt(lines[0]);
        const nums1 = lines[1].split(/\s+/).map(Number);
        const n2 = parseInt(lines[2]);
        const nums2 = lines[3].split(/\s+/).map(Number);
        let map = {};
        for(let i=0; i<n2; i++) map[nums2[i]] = i;
        let res = [];
        for(let num of nums1) {
            let next = -1;
            for(let i=map[num]+1; i<n2; i++) {
                if(nums2[i]>num) { next=nums2[i]; break; }
            }
            res.push(next);
        }
        console.log(res.join(" "));
        rl.close();
    }
});
