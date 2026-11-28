// P001235 - Job Sequencing with Deadlines
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const bills = [];
    for (let i = 0; i < n; i++) bills.push(parseInt(input[1 + i], 10));
    let five = 0, ten = 0;
    for (const bill of bills) {
        if (bill === 5) {
            five++;
        } else if (bill === 10) {
            if (five === 0) { console.log("NO"); return; }
            five--;
            ten++;
        } else if (bill === 20) {
            if (ten > 0 && five > 0) {
                ten--;
                five--;
            } else if (five >= 3) {
                five -= 3;
            } else {
                console.log("NO");
                return;
            }
        }
    }
    console.log("YES");
}

main();
