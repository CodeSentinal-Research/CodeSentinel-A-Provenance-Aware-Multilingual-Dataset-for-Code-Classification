const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1) {
        const n = BigInt(input[0]);
        if (n < 0n) { console.log("Not Perfect Square"); return; }
        let sq = BigInt(Math.floor(Math.sqrt(Number(n))));
        console.log(sq * sq === n ? "Perfect Square" : "Not Perfect Square");
    }
}
main();