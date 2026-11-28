const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const bills = lines[1].split(/\s+/).map(Number);
        
        let five=0, ten=0;
        for(let b of bills) {
            if(b===5) five++;
            else if(b===10) { if(five===0) { console.log("NO"); rl.close(); return; } five--; ten++; }
            else {
                if(ten>0 && five>0) { ten--; five--; }
                else if(five>=3) five-=3;
                else { console.log("NO"); rl.close(); return; }
            }
        }
        console.log("YES");
        rl.close();
    }
});
