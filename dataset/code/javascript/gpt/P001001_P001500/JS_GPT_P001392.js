// P001392 - Count Subarrays Divisible by K
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const arr = [];
    for (let i = 0; i < n; i++) arr.push(parseInt(input[2 + i], 10));
    const count = new Array(k).fill(0);
    count[0] = 1;
    let sum = 0, ans = 0;
    for (const x of arr) {
        sum += x;
        let rem = ((sum % k) + k) % k;
        ans += count[rem];
        count[rem]++;
    }
    console.log(ans);
}

main();
