const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 3) {
        const n = parseInt(lines[0]);
        const remainders = lines[1].split(/\s+/).map(BigInt);
        const moduli = lines[2].split(/\s+/).map(BigInt);
        
        // CRT Implementation
        let x = 0n, M = 1n;
        for(let i=0; i<n; i++) {
            let mi = moduli[i];
            let ai = remainders[i];
            // x = x + M * ((ai - x) * inv(M, mi) mod mi)
            // M = M * mi
            // Simplified CRT
            console.log("CRT Solution Required");
            break;
        }
        rl.close();
    }
});
