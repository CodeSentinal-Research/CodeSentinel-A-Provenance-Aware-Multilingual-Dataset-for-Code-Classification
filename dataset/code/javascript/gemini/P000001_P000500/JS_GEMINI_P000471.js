const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const arr = tokens.slice(1, 1 + n).map(Number);
        const res = [];
        for (let i = 0; i < n; i++) {
            let c = 0;
            for (let j = i + 1; j < n; j++) if (arr[j] < arr[i]) c++;
            res.push(c);
        }
        console.log(res.join(' '));
    }
}
main();