const fs = require('fs');

function main() {
    const lines = fs.readFileSync(0, 'utf-8').trim().split('\n');
    if (lines.length >= 2) {
        const text = lines[0].trim();
        const broken = new Set(lines[1].trim());
        let count = 0;
        for (const w of text.split(/\s+/)) {
            let ok = true;
            for (const c of w) {
                if (broken.has(c)) { ok = false; break; }
            }
            if (ok && w) count++;
        }
        console.log(count);
    }
}

main();