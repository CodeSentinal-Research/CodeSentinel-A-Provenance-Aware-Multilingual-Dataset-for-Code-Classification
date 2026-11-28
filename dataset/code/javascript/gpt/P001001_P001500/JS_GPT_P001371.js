// P001371 - Two Sum
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const target = parseInt(input[1], 10);
    const map = new Map();
    for (let i = 0; i < n; i++) {
        const x = parseInt(input[2 + i], 10);
        const comp = target - x;
        if (map.has(comp)) {
            console.log(map.get(comp) + " " + i);
            return;
        }
        map.set(x, i);
    }
}

main();
