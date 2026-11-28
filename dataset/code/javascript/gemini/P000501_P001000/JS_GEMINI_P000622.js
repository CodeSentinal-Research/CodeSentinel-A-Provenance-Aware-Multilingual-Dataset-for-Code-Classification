const fs = require('fs');
function main() {
    const s = fs.readFileSync(0, 'utf-8').trim();
    if (!s || s === '-1') {
        console.log(0);
    } else {
        console.log(s.split(/\s+/)[0]);
    }
}
main();