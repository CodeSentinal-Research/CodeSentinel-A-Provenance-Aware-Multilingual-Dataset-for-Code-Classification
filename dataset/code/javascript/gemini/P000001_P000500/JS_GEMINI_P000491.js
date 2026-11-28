const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const m = parseInt(tokens[0], 10);
        const target = tokens.slice(1, 1 + m).map(Number);
        const n = parseInt(tokens[1 + m], 10);
        let targetIdx = 0;
        for (let i = 1; i <= n; i++) {
            if (targetIdx === m) break;
            console.log("Push");
            if (target[targetIdx] === i) targetIdx++;
            else console.log("Pop");
        }
    }
}
main();