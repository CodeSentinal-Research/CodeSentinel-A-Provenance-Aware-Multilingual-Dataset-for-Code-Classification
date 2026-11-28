const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+1) {
        const n = parseInt(lines[0]);
        let rooms = [];
        for(let i=1; i<=n; i++) rooms.push(lines[i].split(/\s+/).map(Number));
        let visited = new Set([0]);
        let q = [0];
        while(q.length) {
            let room = q.shift();
            for(let key of rooms[room]) {
                if(!visited.has(key)) {
                    visited.add(key);
                    q.push(key);
                }
            }
        }
        console.log(visited.size===n ? "true" : "false");
        rl.close();
    }
});
