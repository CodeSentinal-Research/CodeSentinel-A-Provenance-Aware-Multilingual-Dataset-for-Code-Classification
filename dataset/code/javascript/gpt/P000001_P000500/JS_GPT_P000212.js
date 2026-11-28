// P000212 - Can Place Flowers
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const size = tokens[p++], n = tokens[p++];
const flowerbed = tokens.slice(p, p + size);
let count = 0;
for (let i = 0; i < size; i++) {
    if (flowerbed[i] === 0) {
        const emptyLeft = (i === 0 || flowerbed[i - 1] === 0);
        const emptyRight = (i === size - 1 || flowerbed[i + 1] === 0);
        if (emptyLeft && emptyRight) {
            flowerbed[i] = 1;
            count++;
        }
    }
}
console.log(count >= n ? "Yes" : "No");
