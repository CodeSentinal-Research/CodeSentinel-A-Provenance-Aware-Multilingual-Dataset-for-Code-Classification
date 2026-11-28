// P001034 - Merge K Sorted Linked Lists
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const k = parseInt(input[0], 10);
    let ptr = 1;
    const all = [];
    for (let i = 0; i < k; i++) {
        const len = parseInt(input[ptr++], 10);
        for (let j = 0; j < len; j++) all.push(parseInt(input[ptr++], 10));
    }
    all.sort((a, b) => a - b);
    console.log(all.join(" "));
}

main();
