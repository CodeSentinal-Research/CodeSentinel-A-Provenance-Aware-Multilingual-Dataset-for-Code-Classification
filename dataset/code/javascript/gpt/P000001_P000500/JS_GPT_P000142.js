// P000142 - Spiral Order Traversal of Matrix
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const rows = tokens[p++], cols = tokens[p++];
const mat = Array.from({length: rows}, () => tokens.slice(p, p += cols));
let top = 0, bottom = rows - 1, left = 0, right = cols - 1;
const result = [];
while (top <= bottom && left <= right) {
    for (let j = left; j <= right; j++) result.push(mat[top][j]);
    top++;
    for (let i = top; i <= bottom; i++) result.push(mat[i][right]);
    right--;
    if (top <= bottom) {
        for (let j = right; j >= left; j--) result.push(mat[bottom][j]);
        bottom--;
    }
    if (left <= right) {
        for (let i = bottom; i >= top; i--) result.push(mat[i][left]);
        left++;
    }
}
console.log(result.join(" "));
