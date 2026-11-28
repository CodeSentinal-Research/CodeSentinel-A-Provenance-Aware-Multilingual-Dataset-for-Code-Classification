const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [w, h, n] = lines[0].split(/\s+/).map(Number);
        let xCoords = [0, w];
        let yCoords = [0, h];
        for(let i=1; i<=n; i++) {
            const [x, y] = lines[i].split(/\s+/).map(Number);
            xCoords.push(x);
            yCoords.push(y);
        }
        xCoords.sort((a,b)=>a-b);
        yCoords.sort((a,b)=>a-b);
        
        let maxXGap = 0;
        for(let i=1; i<xCoords.length; i++) maxXGap = Math.max(maxXGap, xCoords[i]-xCoords[i-1]);
        
        let maxYGap = 0;
        for(let i=1; i<yCoords.length; i++) maxYGap = Math.max(maxYGap, yCoords[i]-yCoords[i-1]);
        
        console.log(maxXGap * maxYGap);
        rl.close();
    }
});
