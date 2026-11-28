// P001305 - Huffman Encoding Cost
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const freq = [];
    for (let i = 0; i < n; i++) freq.push(parseInt(input[1 + i], 10));
    freq.sort((a, b) => a - b);
    let totalCost = 0;
    while (freq.length > 1) {
        const first = freq.shift();
        const second = freq.shift();
        const sum = first + second;
        totalCost += sum;
        let low = 0, high = freq.length;
        while (low < high) {
            const mid = (low + high) >> 1;
            if (freq[mid] < sum) low = mid + 1;
            else high = mid;
        }
        freq.splice(low, 0, sum);
    }
    console.log(totalCost);
}

main();
