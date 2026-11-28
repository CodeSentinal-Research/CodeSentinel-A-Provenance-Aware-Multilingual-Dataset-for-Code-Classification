const fs = require('fs');
function main() {
    const s = fs.readFileSync(0, 'utf-8').trim();
    if (s) {
        const n = s.length;
        const rQ = [], dQ = [];
        for (let i = 0; i < n; i++) {
            if (s[i] === 'R') rQ.push(i);
            else dQ.push(i);
        }
        while (rQ.length > 0 && dQ.length > 0) {
            const rIdx = rQ.shift();
            const dIdx = dQ.shift();
            if (rIdx < dIdx) rQ.push(rIdx + n);
            else dQ.push(dIdx + n);
        }
        console.log(rQ.length > 0 ? "Radiant" : "Dire");
    }
}
main();