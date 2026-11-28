const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === parseInt(lines[0])+1) {
        const n = parseInt(lines[0]);
        let count = {}, dupes = [];
        for(let i=1; i<=n; i++) {
            let email = lines[i];
            count[email] = (count[email]||0)+1;
            if(count[email]===2) dupes.push(email);
        }
        if(dupes.length) console.log(dupes.join("\n"));
        else console.log("No Duplicates");
        rl.close();
    }
});
