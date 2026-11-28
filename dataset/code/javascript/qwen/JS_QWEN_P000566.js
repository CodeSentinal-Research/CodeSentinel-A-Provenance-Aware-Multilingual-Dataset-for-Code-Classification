const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+3) {
        const start = lines[0];
        const end = lines[1];
        const n = parseInt(lines[2]);
        let bank = [];
        for(let i=3; i<3+n; i++) bank.push(lines[i]);
        let set = new Set(bank);
        if(!set.has(end)) { console.log(-1); rl.close(); return; }
        let q = [[start, 0]];
        let visited = new Set([start]);
        let genes = ['A','C','G','T'];
        while(q.length) {
            let [gene, steps] = q.shift();
            if(gene===end) { console.log(steps); rl.close(); return; }
            for(let i=0; i<8; i++) {
                for(let g of genes) {
                    if(gene[i]!==g) {
                        let next = gene.substring(0,i) + g + gene.substring(i+1);
                        if(set.has(next) && !visited.has(next)) {
                            visited.add(next);
                            q.push([next, steps+1]);
                        }
                    }
                }
            }
        }
        console.log(-1);
        rl.close();
    }
});
