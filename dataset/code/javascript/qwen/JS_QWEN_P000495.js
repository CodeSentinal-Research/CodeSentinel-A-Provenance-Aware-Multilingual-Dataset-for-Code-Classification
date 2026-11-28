const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let mod = 10**9+7;
        let res = 0;
        let stack = [];
        for(let i=0; i<=n; i++) {
            let h = i===n ? 0 : arr[i];
            while(stack.length && arr[stack[stack.length-1]] > h) {
                let mid = stack.pop();
                let left = stack.length ? stack[stack.length-1] : -1;
                let right = i;
                let count = (mid - left) * (right - mid);
                res = (res + arr[mid] * count) % mod;
            }
            stack.push(i);
        }
        console.log(res);
        rl.close();
    }
});
