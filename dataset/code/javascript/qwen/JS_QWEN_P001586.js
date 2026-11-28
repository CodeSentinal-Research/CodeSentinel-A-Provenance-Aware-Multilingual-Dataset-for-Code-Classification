const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, carpetLen] = lines[0].split(/\s+/).map(Number);
        let tiles = [];
        for (let i = 1; i <= n; i++) {
            tiles.push(lines[i].split(/\s+/).map(Number));
        }
        
        tiles.sort((a, b) => a[0] - b[0]);
        
        let maxCovered = 0;
        let left = 0;
        
        for (let right = 0; right < n; right++) {
            let start = tiles[left][0];
            let end = tiles[right][1];
            
            while (end - start + 1 > carpetLen) {
                left++;
                start = tiles[left][0];
            }
            
            let coverEnd = start + carpetLen - 1;
            let covered = 0;
            for (let i = left; i <= right; i++) {
                let tileStart = tiles[i][0];
                let tileEnd = tiles[i][1];
                let overlapStart = Math.max(tileStart, start);
                let overlapEnd = Math.min(tileEnd, coverEnd);
                if (overlapEnd >= overlapStart) {
                    covered += (overlapEnd - overlapStart + 1);
                }
            }
            maxCovered = Math.max(maxCovered, covered);
        }
        
        console.log(maxCovered);
        rl.close();
    }
});
