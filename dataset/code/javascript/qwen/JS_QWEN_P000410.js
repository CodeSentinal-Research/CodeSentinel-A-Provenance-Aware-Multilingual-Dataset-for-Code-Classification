const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+2) {
        const n = parseInt(lines[0]);
        const suffix = lines[1];
        let found = false;
        for(let i=2; i<2+n; i++) {
            let pname = lines[i];
            if(pname.endsWith(suffix)) { console.log(pname); found=true; }
        }
        if(!found) console.log("No Products Found");
        rl.close();
    }
});
