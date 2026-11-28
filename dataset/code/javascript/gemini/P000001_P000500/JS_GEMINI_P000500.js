const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const ops = tokens.slice(1, 1 + n);
        let depth = 0;
        for (const op of ops) {
            if (op === '../') {
                if (depth > 0) depth--;
            } else if (op === './') {
            } else {
                depth++;
            }
        }
        console.log(depth);
    }
}
main();