const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 3) {
        const n = parseInt(lines[0]);
        let dict = new Set();
        for(let i=1; i<=n; i++) dict.add(lines[i]);
        const [start, end] = lines[n+1].split(/\s+/);
        
        if(!dict.has(end)) { console.log(0); rl.close(); return; }
        
        let queue = [[start, 1]];
        let visited = new Set([start]);
        while(queue.length > 0) {
            let [word, steps] = queue.shift();
            if(word === end) { console.log(steps); rl.close(); return; }
            
            for(let i=0; i<word.length; i++) {
                for(let c=97; c<=122; c++) {
                    let next = word.substring(0,i) + String.fromCharCode(c) + word.substring(i+1);
                    if(dict.has(next) && !visited.has(next)) {
                        visited.add(next);
                        queue.push([next, steps+1]);
                    }
                }
            }
        }
        console.log(0);
        rl.close();
    }
});
