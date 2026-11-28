// P001341 - Binary Watch
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim();
    if (!input) return;
    const turnedOn = parseInt(input, 10);
    function countBits(n) {
        let count = 0;
        while (n > 0) {
            count += (n & 1);
            n >>= 1;
        }
        return count;
    }
    const res = [];
    for (let h = 0; h < 12; h++) {
        for (let m = 0; m < 60; m++) {
            if (countBits(h) + countBits(m) === turnedOn) {
                res.push(h + ":" + (m < 10 ? "0" + m : m));
            }
        }
    }
    console.log(res.join(" "));
}

main();
