const fs = require('fs');

function main() {
    const words = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    const r1 = new Set('qwertyuiop'), r2 = new Set('asdfghjkl'), r3 = new Set('zxcvbnm');
    for (const w of words) {
        if (!w) continue;
        let inR1 = true, inR2 = true, inR3 = true;
        for (const c of w.toLowerCase()) {
            if (!r1.has(c)) inR1 = false;
            if (!r2.has(c)) inR2 = false;
            if (!r3.has(c)) inR3 = false;
        }
        if (inR1 || inR2 || inR3) {
            console.log(w);
        }
    }
}

main();