const fs = require('fs');
function main() {
    const s = fs.readFileSync(0, 'utf-8').trim();
    if (s) console.log(s.split(/\s+/)[0]);
}
main();