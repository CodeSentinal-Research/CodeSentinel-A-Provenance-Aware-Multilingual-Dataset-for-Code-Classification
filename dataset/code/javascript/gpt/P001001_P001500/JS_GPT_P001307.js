// P001307 - Police and Thieves
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const arr = [];
    for (let i = 0; i < n; i++) arr.push(input[2 + i]);
    const police = [], thieves = [];
    for (let i = 0; i < n; i++) {
        if (arr[i] === "P") police.push(i);
        else if (arr[i] === "T") thieves.push(i);
    }
    let p = 0, t = 0, caught = 0;
    while (p < police.length && t < thieves.length) {
        if (Math.abs(police[p] - thieves[t]) <= k) {
            caught++;
            p++;
            t++;
        } else if (police[p] < thieves[t]) {
            p++;
        } else {
            t++;
        }
    }
    console.log(caught);
}

main();
