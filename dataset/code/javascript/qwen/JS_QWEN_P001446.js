const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const s1 = lines[0];
        const s2 = lines[1];
        const n = parseInt(lines[2]);
        let pairs = [];
        for (let i = 3; i < 3 + n; i++) pairs.push(lines[i].split(/\s+/));
        
        let map = {};
        for (let [a, b] of pairs) {
            map[a] = b;
            map[b] = a;
        }
        
        let similar = true;
        if (s1.length !== s2.length) similar = false;
        else {
            for (let i = 0; i < s1.length; i++) {
                if (s1[i] !== s2[i] && map[s1[i]] !== s2[i]) {
                    similar = false;
                    break;
                }
            }
        }
        console.log(similar ? "YES" : "NO");
        rl.close();
    }
});
