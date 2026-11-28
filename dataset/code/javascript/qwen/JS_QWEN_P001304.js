const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const [r, c] = lines[0].split(/\s+/).map(Number);
        const hCuts = lines[1].split(/\s+/).map(Number).sort((a,b)=>b-a);
        const vCuts = lines[2].split(/\s+/).map(Number).sort((a,b)=>b-a);
        
        // Greedy: cut most expensive first
        let cost = 0;
        let hPieces = 1, vPieces = 1;
        let i=0, j=0;
        while(i<hCuts.length && j<vCuts.length) {
            if(hCuts[i] > vCuts[j]) {
                cost += hCuts[i] * vPieces;
                hPieces++;
                i++;
            } else {
                cost += vCuts[j] * hPieces;
                vPieces++;
                j++;
            }
        }
        while(i<hCuts.length) {
            cost += hCuts[i] * vPieces;
            i++;
        }
        while(j<vCuts.length) {
            cost += vCuts[j] * hPieces;
            j++;
        }
        console.log(cost);
        rl.close();
    }
});
