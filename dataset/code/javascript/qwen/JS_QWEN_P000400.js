const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+3) {
        const n = parseInt(lines[0]);
        const [minS, maxS] = lines[1].split(/\s+/).map(Number);
        let found = false;
        for(let i=2; i<2+n; i++) {
            let [ename, salary] = lines[i].split(/\s+/);
            salary = parseFloat(salary);
            if(salary >= minS && salary <= maxS) { console.log(`${ename} ${salary}`); found=true; }
        }
        if(!found) console.log("No Employees Found");
        rl.close();
    }
});
