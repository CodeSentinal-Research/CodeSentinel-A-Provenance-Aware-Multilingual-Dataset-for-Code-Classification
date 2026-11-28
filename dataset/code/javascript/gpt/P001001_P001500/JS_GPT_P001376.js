// P001376 - Group Anagrams
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const map = new Map();
    for (let i = 0; i < n; i++) {
        const word = input[1 + i];
        const key = word.split("").sort().join("");
        if (!map.has(key)) map.set(key, []);
        map.get(key).push(word);
    }
    for (const group of map.values()) {
        console.log(group.join(" "));
    }
}

main();
