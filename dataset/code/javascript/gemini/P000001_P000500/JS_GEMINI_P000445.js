const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 3 && tokens[0] !== '') {
        const r = parseInt(tokens[0], 10);
        const c = parseInt(tokens[1], 10);
        const target = Number(tokens[2]);
        const mat = tokens.slice(3, 3 + r * c).map(Number);
        console.log(mat.includes(target) ? "Found" : "Not Found");
    }
}
main();