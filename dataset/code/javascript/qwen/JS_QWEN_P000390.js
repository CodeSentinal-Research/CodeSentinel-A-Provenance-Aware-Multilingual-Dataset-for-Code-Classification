const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+3) {
        const n = parseInt(lines[0]);
        const [minP, maxP] = lines[1].split(/\s+/).map(Number);
        let found = false;
        for(let i=2; i<2+n; i++) {
            let [pname, price] = lines[i].split(/\s+/);
            price = parseFloat(price);
            if(price >= minP && price <= maxP) { console.log(`${pname} ${price}`); found=true; }
        }
        if(!found) console.log("No Products Found");
        rl.close();
    }
});
