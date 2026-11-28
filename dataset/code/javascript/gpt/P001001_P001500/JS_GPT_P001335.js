// P001335 - Matchsticks to Square
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const sticks = [];
    let sum = 0;
    for (let i = 0; i < n; i++) {
        const x = parseInt(input[1 + i], 10);
        sticks.push(x);
        sum += x;
    }
    if (sum % 4 !== 0 || n < 4) { console.log("NO"); return; }
    const side = sum / 4;
    sticks.sort((a, b) => b - a);
    if (sticks[0] > side) { console.log("NO"); return; }
    const sides = [0, 0, 0, 0];
    function backtrack(idx) {
        if (idx === n) {
            return sides[0] === side && sides[1] === side && sides[2] === side;
        }
        for (let i = 0; i < 4; i++) {
            if (sides[i] + sticks[idx] <= side) {
                sides[i] += sticks[idx];
                if (backtrack(idx + 1)) return true;
                sides[i] -= sticks[idx];
            }
            if (sides[i] === 0) break;
        }
        return false;
    }
    console.log(backtrack(0) ? "YES" : "NO");
}

main();
