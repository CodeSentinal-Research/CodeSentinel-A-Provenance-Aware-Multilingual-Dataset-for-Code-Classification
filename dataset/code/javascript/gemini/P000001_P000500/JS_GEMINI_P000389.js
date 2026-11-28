const fs = require('fs');

function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const records = [];
        let idx = 1;
        for (let i = 0; i < n; i++) {
            records.push({name: tokens[idx], dept: tokens[idx + 1]});
            idx += 2;
        }
        const targetDept = tokens[idx];
        const matches = records.filter(r => r.dept === targetDept);
        if (matches.length > 0) {
            matches.forEach(m => console.log(m.name));
        } else {
            console.log("No Records Found");
        }
    }
}

main();