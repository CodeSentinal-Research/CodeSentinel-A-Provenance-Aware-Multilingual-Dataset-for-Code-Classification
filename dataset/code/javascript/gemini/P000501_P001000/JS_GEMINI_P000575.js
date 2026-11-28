const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim();
    if (!input) { console.log(0); return; }
    const tokens = input.split(/\s+/);
    if (tokens.length === 0 || ['null', '#', 'N'].includes(tokens[0])) { console.log(0); return; }
    const q = [[0, 1n]];
    let maxW = 0n;
    while (q.length > 0) {
        const sz = q.length;
        const firstPos = q[0][1], lastPos = q[sz - 1][1];
        const curW = lastPos - firstPos + 1n;
        if (curW > maxW) maxW = curW;
        for (let i = 0; i < sz; i++) {
            const [idx, pos] = q.shift();
            const l = 2 * idx + 1, r = 2 * idx + 2;
            if (l < tokens.length && !['null', '#', 'N'].includes(tokens[l])) {
                q.push([l, 2n * pos]);
            }
            if (r < tokens.length && !['null', '#', 'N'].includes(tokens[r])) {
                q.push([r, 2n * pos + 1n]);
            }
        }
    }
    console.log(maxW.toString());
}
main();