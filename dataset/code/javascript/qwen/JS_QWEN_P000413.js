const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+3) {
        const n = parseInt(lines[0]);
        const dept = lines[1];
        let found = false;
        for(let i=2; i<2+n; i++) {
            let [ename, edept, status] = lines[i].split(/\s+/);
            if(edept === dept && status === "Active") { console.log(`${ename} ${edept}`); found=true; }
        }
        if(!found) console.log("No Employees Found");
        rl.close();
    }
});
