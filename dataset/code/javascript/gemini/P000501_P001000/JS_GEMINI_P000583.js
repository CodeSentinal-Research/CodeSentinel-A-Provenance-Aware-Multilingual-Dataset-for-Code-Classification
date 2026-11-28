const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim();
    if (!input || input === '-1') {
        console.log("false");
    } else {
        console.log("true");
    }
}
main();