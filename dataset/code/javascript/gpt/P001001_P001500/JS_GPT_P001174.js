// P001174 - Triangle Minimum Path Sum
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const triangle = [];
    for (let i = 0; i < n; i++) {
        const row = [];
        for (let j = 0; j <= i; j++) row.push(parseInt(input[ptr++], 10));
        triangle.push(row);
    }
    for (let i = n - 2; i >= 0; i--) {
        for (let j = 0; j <= i; j++) {
            triangle[i][j] += Math.min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }
    console.log(triangle[0][0]);
}

main();
