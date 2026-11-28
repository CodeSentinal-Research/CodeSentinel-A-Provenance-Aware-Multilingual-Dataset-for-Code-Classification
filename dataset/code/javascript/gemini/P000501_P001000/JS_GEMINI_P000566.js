const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 3 && tokens[0] !== '') {
        const startGene = tokens[0], endGene = tokens[1];
        const n = parseInt(tokens[2], 10);
        const bank = new Set(tokens.slice(3, 3 + n));
        if (!bank.has(endGene)) { console.log(-1); return; }
        const q = [[startGene, 0]];
        const vis = new Set([startGene]);
        let ans = -1;
        while (q.length > 0) {
            const [gene, step] = q.shift();
            if (gene === endGene) { ans = step; break; }
            for (let i = 0; i < 8; i++) {
                for (const c of ['A', 'C', 'G', 'T']) {
                    const nxt = gene.slice(0, i) + c + gene.slice(i + 1);
                    if (bank.has(nxt) && !vis.has(nxt)) {
                        vis.add(nxt);
                        q.push([nxt, step + 1]);
                    }
                }
            }
        }
        console.log(ans);
    }
}
main();