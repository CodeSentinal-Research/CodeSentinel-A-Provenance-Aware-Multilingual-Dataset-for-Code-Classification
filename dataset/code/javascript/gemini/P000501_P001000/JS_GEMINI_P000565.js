const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 4 && tokens[0] !== '') {
        const rows = parseInt(tokens[0], 10), cols = parseInt(tokens[1], 10);
        const r0 = parseInt(tokens[2], 10), c0 = parseInt(tokens[3], 10);
        const cells = [];
        for (let r = 0; r < rows; r++) {
            for (let c = 0; c < cols; c++) cells.push([r, c]);
        }
        cells.sort((a, b) => (Math.abs(a[0] - r0) + Math.abs(a[1] - c0)) - (Math.abs(b[0] - r0) + Math.abs(b[1] - c0)));
        console.log(cells.map(([r, c]) => `[${r},${c}]`).join(' '));
    }
}
main();