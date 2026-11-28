const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const m = parseInt(lines[0]);
        let wins = [], losses = [];
        let winCount = {}, lossCount = {}, played = new Set();
        
        for (let i = 1; i <= m; i++) {
            const [w, l] = lines[i].split(/\s+/).map(Number);
            winCount[w] = (winCount[w] || 0) + 1;
            lossCount[l] = (lossCount[l] || 0) + 1;
            played.add(w);
            played.add(l);
        }
        
        let noLoss = [], oneLoss = [];
        for (let p of played) {
            if (!lossCount[p]) noLoss.push(p);
            else if (lossCount[p] === 1) oneLoss.push(p);
        }
        console.log(noLoss.sort((a,b)=>a-b).join(" "));
        console.log(oneLoss.sort((a,b)=>a-b).join(" "));
        rl.close();
    }
});
