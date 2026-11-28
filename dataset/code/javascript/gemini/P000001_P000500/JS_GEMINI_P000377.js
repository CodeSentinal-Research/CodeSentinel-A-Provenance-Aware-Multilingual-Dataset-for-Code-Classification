const fs = require('fs');

function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const records = new Map();
        let idx = 1;
        for (let i = 0; i < n; i++) {
            records.set(tokens[idx], tokens[idx + 1]);
            idx += 2;
        }
        const target = tokens[idx];
        if (records.has(target)) {
            console.log(`${target} ${records.get(target)}`);
        } else {
            console.log("Vehicle Not Found");
        }
    }
}

main();