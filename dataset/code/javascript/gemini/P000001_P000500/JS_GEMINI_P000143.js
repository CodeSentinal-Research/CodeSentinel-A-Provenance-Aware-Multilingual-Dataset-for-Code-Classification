const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 2) {
        const r = parseInt(input[0], 10), c = parseInt(input[1], 10);
        const grid = [];
        let ptr = 2;
        for (let i = 0; i < r; i++) {
            grid.push(input.slice(ptr, ptr + c));
            ptr += c;
        }
        for (let j = 0; j < c; j++) {
            const col = [];
            for (let i = 0; i < r; i++) col.push(grid[i][j]);
            console.log(col.join(' '));
        }
    }
}
main();