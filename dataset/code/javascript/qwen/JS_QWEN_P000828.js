const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0]) + 1) {
        const n = parseInt(lines[0]);
        let intervals = [];
        for (let i = 1; i <= n; i++) intervals.push(lines[i].split(/\s+/).map(Number));
        
        let starts = intervals.map(x => x[0]);
        let sortedStarts = [...starts].sort((a,b)=>a-b);
        
        let res = [];
        for (let i = 0; i < n; i++) {
            let end = intervals[i][1];
            let l = 0, r = n - 1, idx = -1;
            while (l <= r) {
                let m = Math.floor((l + r) / 2);
                if (sortedStarts[m] >= end) { idx = m; r = m - 1; }
                else l = m + 1;
            }
            res.push(idx === -1 ? -1 : starts.indexOf(sortedStarts[idx])); // Note: indexOf might be slow if duplicates, but problem says unique starts
        }
        console.log(res.join(" "));
        rl.close();
    }
});
