// P001340 - Fair Distribution of Cookies
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const cookies = [];
    for (let i = 0; i < n; i++) cookies.push(parseInt(input[2 + i], 10));
    cookies.sort((a, b) => b - a);
    const dist = new Array(k).fill(0);
    let minUnfairness = Infinity;
    function backtrack(idx) {
        if (idx === n) {
            minUnfairness = Math.min(minUnfairness, Math.max(...dist));
            return;
        }
        for (let i = 0; i < k; i++) {
            if (dist[i] + cookies[idx] >= minUnfairness) continue;
            dist[i] += cookies[idx];
            backtrack(idx + 1);
            dist[i] -= cookies[idx];
            if (dist[i] === 0) break;
        }
    }
    backtrack(0);
    console.log(minUnfairness);
}

main();
