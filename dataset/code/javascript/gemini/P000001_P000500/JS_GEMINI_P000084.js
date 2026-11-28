const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1) {
        const age = parseInt(input[0], 10);
        console.log(age >= 18 ? "Eligible" : "Not Eligible");
    }
}
main();