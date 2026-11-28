const fs = require('fs');

function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        let idx = 1;
        for (let i = 0; i < n; i++) {
            const uname = tokens[idx];
            const status = (tokens[idx + 1] || '').toLowerCase();
            if (["active", "true", "1", "yes", "enabled"].includes(status)) {
                console.log(uname);
            }
            idx += 2;
        }
    }
}

main();