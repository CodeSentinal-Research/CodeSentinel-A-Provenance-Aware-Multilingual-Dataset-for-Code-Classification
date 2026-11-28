// P001393 - Continuous Subarray Sum
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const arr = [];
    for (let i = 0; i < n; i++) arr.push(parseInt(input[2 + i], 10));
    const map = new Map();
    map.set(0, -1);
    let sum = 0;
    for (let i = 0; i < n; i++) {
        sum += arr[i];
        let rem = k !== 0 ? ((sum % k) + k) % k : sum;
        if (map.has(rem)) {
            if (i - map.get(rem) >= 2) {
                console.log("YES");
                return;
            }
        } else {
            map.set(rem, i);
        }
    }
    console.log("NO");
}

main();
