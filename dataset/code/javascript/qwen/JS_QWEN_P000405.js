const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+2) {
        const n = parseInt(lines[0]);
        const instr = lines[1];
        let found = false;
        for(let i=2; i<2+n; i++) {
            let [cname, cinstr] = lines[i].split(/\s+/);
            if(cinstr === instr) { console.log(`${cname} ${cinstr}`); found=true; }
        }
        if(!found) console.log("No Courses Found");
        rl.close();
    }
});
