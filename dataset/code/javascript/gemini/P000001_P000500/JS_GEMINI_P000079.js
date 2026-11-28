const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1) {
        const s = parseInt(input[0], 10);
        const h = Math.floor(s / 3600);
        const rem = s % 3600;
        const m = Math.floor(rem / 60);
        const sec = rem % 60;
        console.log(`${h} Hours ${m} Minutes ${sec} Seconds`);
    }
}
main();