const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        let votes = [];
        for (let i = 1; i <= n; i++) votes.push(lines[i]);
        
        let count = {};
        for (let v of votes) {
            for (let i = 0; i < v.length; i++) {
                let c = v[i];
                if (!count[c]) count[c] = new Array(v.length).fill(0);
                count[c][i]++;
            }
        }
        
        let candidates = Object.keys(count).sort();
        candidates.sort((a, b) => {
            for (let i = 0; i < votes[0].length; i++) {
                if (count[a][i] !== count[b][i]) return count[b][i] - count[a][i];
            }
            return a.charCodeAt(0) - b.charCodeAt(0);
        });
        console.log(candidates.join(''));
        rl.close();
    }
});
