const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const k = parseInt(tokens[0], 10);
        let idx = 1;
        const allVals = [];
        for (let i = 0; i < k; i++) {
            const size = parseInt(tokens[idx++], 10);
            for (let j = 0; j < size; j++) allVals.push(Number(tokens[idx++]));
        }
        allVals.sort((a, b) => a - b);
        console.log(allVals.join(' '));
    }
}
main();