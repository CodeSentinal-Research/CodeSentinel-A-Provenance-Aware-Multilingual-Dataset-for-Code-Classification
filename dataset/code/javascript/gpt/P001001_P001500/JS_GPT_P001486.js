// P001486 - Compare Version Numbers
const fs = require("fs");

function main() {
    const lines = fs.readFileSync(0, "utf8").trim().split(/\r?\n/);
    if (!lines || lines.length < 2) return;
    const v1 = lines[0].trim().split(".").map(x => parseInt(x, 10));
    const v2 = lines[1].trim().split(".").map(x => parseInt(x, 10));
    const len = Math.max(v1.length, v2.length);
    for (let i = 0; i < len; i++) {
        const val1 = i < v1.length ? v1[i] : 0;
        const val2 = i < v2.length ? v2[i] : 0;
        if (val1 > val2) {
            console.log(1);
            return;
        } else if (val1 < val2) {
            console.log(-1);
            return;
        }
    }
    console.log(0);
}

main();
