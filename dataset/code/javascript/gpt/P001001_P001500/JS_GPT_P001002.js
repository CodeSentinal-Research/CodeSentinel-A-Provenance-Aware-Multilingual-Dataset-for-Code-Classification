// P001002 - Check Max Heap Property
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const arr = [];
    for (let i = 0; i < n; i++) {
        arr.push(parseInt(input[1 + i], 10));
    }
    for (let i = 0; i <= Math.floor((n - 2) / 2); i++) {
        const left = 2 * i + 1;
        const right = 2 * i + 2;
        if (left < n && arr[i] < arr[left]) {
            console.log("NO");
            return;
        }
        if (right < n && arr[i] < arr[right]) {
            console.log("NO");
            return;
        }
    }
    console.log("YES");
}

main();
