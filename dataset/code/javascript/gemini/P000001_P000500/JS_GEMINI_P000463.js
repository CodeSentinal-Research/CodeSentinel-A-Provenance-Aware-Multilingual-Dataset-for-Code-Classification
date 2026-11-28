const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 3 && tokens[0] !== '') {
        const n1 = parseInt(tokens[0], 10), n2 = parseInt(tokens[1], 10), n3 = parseInt(tokens[2], 10);
        let idx = 3;
        const a1 = new Set(tokens.slice(idx, idx + n1).map(Number)); idx += n1;
        const a2 = new Set(tokens.slice(idx, idx + n2).map(Number)); idx += n2;
        const a3 = new Set(tokens.slice(idx, idx + n3).map(Number)); idx += n3;
        const common = [...a1].filter(x => a2.has(x) && a3.has(x)).sort((x, y) => x - y);
        console.log(common.length > 0 ? common.join(' ') : -1);
    }
}
main();