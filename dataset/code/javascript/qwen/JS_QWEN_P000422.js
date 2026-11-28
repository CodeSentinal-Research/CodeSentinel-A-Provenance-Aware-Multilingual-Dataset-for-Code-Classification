const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+3) {
        const n = parseInt(lines[0]);
        const minCgpa = parseFloat(lines[1]);
        const maxIncome = parseFloat(lines[2]);
        let found = false;
        for(let i=3; i<3+n; i++) {
            let [sname, cgpa, income] = lines[i].split(/\s+/);
            if(parseFloat(cgpa) >= minCgpa && parseFloat(income) <= maxIncome) { console.log(sname); found=true; }
        }
        if(!found) console.log("No Eligible Students");
        rl.close();
    }
});
