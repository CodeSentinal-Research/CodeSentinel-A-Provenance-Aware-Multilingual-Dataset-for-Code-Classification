// P001337 - Beautiful Arrangement
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim();
    if (!input) return;
    const n = parseInt(input, 10);
    const visited = new Array(n + 1).fill(false);
    let count = 0;
    function backtrack(pos) {
        if (pos > n) {
            count++;
            return;
        }
        for (let i = 1; i <= n; i++) {
            if (!visited[i] && (i % pos === 0 || pos % i === 0)) {
                visited[i] = true;
                backtrack(pos + 1);
                visited[i] = false;
            }
        }
    }
    backtrack(1);
    console.log(count);
}

main();
