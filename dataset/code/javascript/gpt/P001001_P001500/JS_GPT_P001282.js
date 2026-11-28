// P001282 - Create Maximum Number
const fs = require("fs");

function maxSub(nums, k) {
    const stack = [];
    let drop = nums.length - k;
    for (const x of nums) {
        while (stack.length > 0 && drop > 0 && stack[stack.length - 1] < x) {
            stack.pop();
            drop--;
        }
        stack.push(x);
    }
    return stack.slice(0, k);
}

function merge(a, b) {
    const res = [];
    let i = 0, j = 0;
    while (i < a.length || j < b.length) {
        if (greater(a, i, b, j)) res.push(a[i++]);
        else res.push(b[j++]);
    }
    return res;
}

function greater(a, i, b, j) {
    while (i < a.length && j < b.length && a[i] === b[j]) {
        i++;
        j++;
    }
    return j === b.length || (i < a.length && a[i] > b[j]);
}

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    const k = parseInt(input[2], 10);
    let ptr = 3;
    const a = [];
    for (let i = 0; i < n; i++) a.push(parseInt(input[ptr++], 10));
    const b = [];
    for (let i = 0; i < m; i++) b.push(parseInt(input[ptr++], 10));
    let best = [];
    for (let i = Math.max(0, k - m); i <= Math.min(k, n); i++) {
        const subA = maxSub(a, i);
        const subB = maxSub(b, k - i);
        const cand = merge(subA, subB);
        if (greater(cand, 0, best, 0)) best = cand;
    }
    console.log(best.join(" "));
}

main();
