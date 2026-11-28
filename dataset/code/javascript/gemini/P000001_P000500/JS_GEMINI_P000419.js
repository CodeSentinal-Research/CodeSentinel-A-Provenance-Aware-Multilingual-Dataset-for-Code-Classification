const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        let idx = 1;
        for (let i = 0; i < n; i++) {
            const dev = tokens[idx];
            const st = (tokens[idx+1] || '').toLowerCase();
            if (["online", "active", "true", "1", "yes"].includes(st)) {
                console.log(dev);
            }
            idx += 2;
        }
    }
}
main();