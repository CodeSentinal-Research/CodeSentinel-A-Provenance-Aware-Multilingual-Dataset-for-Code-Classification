// P001283 - Queue Reconstruction by Increasing Height
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const people = [];
    for (let i = 0; i < n; i++) {
        people.push([parseInt(input[ptr++], 10), parseInt(input[ptr++], 10)]);
    }
    people.sort((a, b) => (b[0] !== a[0] ? b[0] - a[0] : a[1] - b[1]));
    const res = [];
    for (const p of people) {
        res.splice(p[1], 0, p);
    }
    for (const p of res) console.log(p[0] + " " + p[1]);
}

main();
