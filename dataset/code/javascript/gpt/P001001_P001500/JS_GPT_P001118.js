// P001118 - Alien Dictionary
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const words = [];
    for (let i = 0; i < n; i++) words.push(input[1 + i]);
    const adj = new Map();
    const inDegree = new Map();
    for (const w of words) {
        for (const c of w) {
            if (!adj.has(c)) adj.set(c, new Set());
            if (!inDegree.has(c)) inDegree.set(c, 0);
        }
    }
    for (let i = 0; i < n - 1; i++) {
        const w1 = words[i], w2 = words[i + 1];
        if (w1.length > w2.length && w1.startsWith(w2)) {
            console.log("");
            return;
        }
        for (let j = 0; j < Math.min(w1.length, w2.length); j++) {
            if (w1[j] !== w2[j]) {
                if (!adj.get(w1[j]).has(w2[j])) {
                    adj.get(w1[j]).add(w2[j]);
                    inDegree.set(w2[j], inDegree.get(w2[j]) + 1);
                }
                break;
            }
        }
    }
    const queue = [];
    for (const [c, deg] of inDegree.entries()) {
        if (deg === 0) queue.push(c);
    }
    const order = [];
    while (queue.length > 0) {
        const c = queue.shift();
        order.push(c);
        for (const nextC of adj.get(c)) {
            inDegree.set(nextC, inDegree.get(nextC) - 1);
            if (inDegree.get(nextC) === 0) queue.push(nextC);
        }
    }
    if (order.length === inDegree.size) {
        console.log(order.join(""));
    } else {
        console.log("");
    }
}

main();
