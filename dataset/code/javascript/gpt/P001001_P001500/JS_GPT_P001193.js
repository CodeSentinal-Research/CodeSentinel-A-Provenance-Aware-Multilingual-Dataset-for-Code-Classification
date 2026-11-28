// P001193 - House Robber III
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const tree = [];
    for (let i = 0; i < n; i++) tree.push(parseInt(input[1 + i], 10));
    function rob(i) {
        if (i >= n || tree[i] === -1) return [0, 0];
        const left = rob(2 * i + 1);
        const right = rob(2 * i + 2);
        const robRoot = tree[i] + left[1] + right[1];
        const skipRoot = Math.max(left[0], left[1]) + Math.max(right[0], right[1]);
        return [robRoot, skipRoot];
    }
    const res = rob(0);
    console.log(Math.max(res[0], res[1]));
}

main();
