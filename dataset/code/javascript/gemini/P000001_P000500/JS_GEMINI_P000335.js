const fs = require('fs');

function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2) {
        const pattern = tokens[tokens.length - 1];
        const queries = tokens.slice(0, tokens.length - 1);
        for (const q of queries) {
            let i = 0, ok = true;
            for (let j = 0; j < q.length; j++) {
                const c = q[j];
                if (i < pattern.length && c === pattern[i]) {
                    i++;
                } else if (c >= 'A' && c <= 'Z') {
                    ok = false;
                    break;
                }
            }
            console.log(ok && i === pattern.length ? "true" : "false");
        }
    }
}

main();