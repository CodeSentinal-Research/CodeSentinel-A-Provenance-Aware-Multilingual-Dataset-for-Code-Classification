const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+2) {
        const n = parseInt(lines[0]);
        const code = lines[1];
        let found = false;
        for(let i=2; i<2+n; i++) {
            let [ecode, name] = lines[i].split(/\s+/);
            if(ecode === code) { console.log(`${ecode} ${name}`); found=true; break; }
        }
        if(!found) console.log("Product Not Found");
        rl.close();
    }
});
