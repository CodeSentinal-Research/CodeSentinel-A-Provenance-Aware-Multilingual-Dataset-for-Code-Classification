// P001494 - DI String Match
const fs = require("fs");

function main() {
    const s = fs.readFileSync(0, "utf8").trim();
    if (!s) return;
    let low = 0, high = s.length;
    const res = [];
    for (let i = 0; i < s.length; i++) {
        if (s[i] === 'I') {
            res.push(low++);
        } else {
            res.push(high--);
        }
    }
    res.push(low);
    console.log(res.join(" "));
}

main();
