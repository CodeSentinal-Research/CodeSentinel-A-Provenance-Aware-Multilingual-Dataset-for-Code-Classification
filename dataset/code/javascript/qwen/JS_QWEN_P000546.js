const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const s = lines[0];
        const minJump = parseInt(lines[1]);
        const maxJump = parseInt(lines[2]);
        let n = s.length;
        let reachable = new Array(n).fill(false);
        reachable[0] = true;
        let q = [0];
        let farthest = 0;
        for(let i=0; i<n; i++) {
            if(reachable[i]) {
                let start = Math.max(i+minJump, farthest+1);
                let end = Math.min(i+maxJump, n-1);
                for(let j=start; j<=end; j++) {
                    if(s[j]==='0') {
                        reachable[j] = true;
                        q.push(j);
                    }
                }
                farthest = Math.max(farthest, end);
            }
        }
        console.log(reachable[n-1] ? "true" : "false");
        rl.close();
    }
});
