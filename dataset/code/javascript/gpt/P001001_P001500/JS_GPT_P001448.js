// P001448 - Verify Alien Dictionary
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const words = [];
    for (let i = 0; i < n; i++) words.push(input[1 + i]);
    const order = input[1 + n];
    const orderMap = new Map();
    for (let i = 0; i < order.length; i++) orderMap.set(order[i], i);

    for (let i = 0; i < n - 1; i++) {
        const w1 = words[i], w2 = words[i + 1];
        let sorted = false;
        for (let j = 0; j < Math.min(w1.length, w2.length); j++) {
            if (w1[j] !== w2[j]) {
                if (orderMap.get(w1[j]) > orderMap.get(w2[j])) {
                    console.log("NO");
                    return;
                }
                sorted = true;
                break;
            }
        }
        if (!sorted && w1.length > w2.length) {
            console.log("NO");
            return;
        }
    }
    console.log("YES");
}

main();
