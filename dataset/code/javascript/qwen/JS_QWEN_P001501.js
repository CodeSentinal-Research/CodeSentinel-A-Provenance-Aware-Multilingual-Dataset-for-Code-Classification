const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const seats = lines[1].split(/\s+/).map(Number);
        
        let maxDist = 0;
        let lastOccupied = -1;
        
        // Check distance from start to first occupied
        let firstOccupied = seats.indexOf(1);
        if (firstOccupied !== -1) maxDist = firstOccupied;
        
        // Check distances between occupied seats
        for (let i = 0; i < n; i++) {
            if (seats[i] === 1) {
                if (lastOccupied !== -1) {
                    maxDist = Math.max(maxDist, Math.floor((i - lastOccupied) / 2));
                }
                lastOccupied = i;
            }
        }
        
        // Check distance from last occupied to end
        if (lastOccupied !== -1) {
            maxDist = Math.max(maxDist, n - 1 - lastOccupied);
        }
        
        console.log(maxDist);
        rl.close();
    }
});
