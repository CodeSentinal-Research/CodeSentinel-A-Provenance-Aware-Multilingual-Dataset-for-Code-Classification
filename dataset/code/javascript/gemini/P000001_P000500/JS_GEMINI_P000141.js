const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1) {
        const n = parseInt(input[0], 10);
        const grid = [];
        let ptr = 1;
        for (let i = 0; i < n; i++) {
            grid.push(input.slice(ptr, ptr + n).map(Number));
            ptr += n;
        }
        for (let i = 0; i < n; i++) {
            const row = [];
            for (let j = 0; j < n; j++) row.push(grid[n - 1 - j][i]);
            console.log(row.join(' '));
        }
    }
}
main();