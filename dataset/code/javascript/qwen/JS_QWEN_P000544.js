const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+2) {
        const d = parseInt(lines[0]);
        const deadends = new Set(lines[1].split(/\s+/));
        const target = lines[2];
        if(deadends.has("0000")) { console.log(-1); rl.close(); return; }
        let q = [["0000", 0]];
        let visited = new Set(["0000"]);
        while(q.length) {
            let [curr, moves] = q.shift();
            if(curr===target) { console.log(moves); rl.close(); return; }
            for(let i=0; i<4; i++) {
                for(let delta of [-1, 1]) {
                    let next = curr.split('');
                    next[i] = (parseInt(next[i]) + delta + 10) % 10;
                    let nextStr = next.join('');
                    if(!visited.has(nextStr) && !deadends.has(nextStr)) {
                        visited.add(nextStr);
                        q.push([nextStr, moves+1]);
                    }
                }
            }
        }
        console.log(-1);
        rl.close();
    }
});
