// P001200 - Maximal Rectangle
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const r = parseInt(input[0], 10);
    const c = parseInt(input[1], 10);
    let ptr = 2;
    const matrix = [];
    for (let i = 0; i < r; i++) {
        const row = [];
        for (let j = 0; j < c; j++) row.push(parseInt(input[ptr++], 10));
        matrix.push(row);
    }
    const heights = new Array(c + 1).fill(0);
    let maxArea = 0;
    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
            heights[j] = matrix[i][j] === 1 ? heights[j] + 1 : 0;
        }
        const stack = [];
        for (let j = 0; j <= c; j++) {
            while (stack.length > 0 && heights[stack[stack.length - 1]] >= heights[j]) {
                const h = heights[stack.pop()];
                const w = stack.length === 0 ? j : j - stack[stack.length - 1] - 1;
                maxArea = Math.max(maxArea, h * w);
            }
            stack.push(j);
        }
    }
    console.log(maxArea);
}

main();
