const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const size = parseInt(tokens[0], 10), q = parseInt(tokens[1], 10);
        const stream = tokens.slice(2, 2 + q).map(Number);
        const window = [];
        let sum = 0;
        for (const val of stream) {
            window.push(val);
            sum += val;
            if (window.length > size) {
                sum -= window.shift();
            }
            console.log((sum / window.length).toFixed(5));
        }
    }
}
main();