// P001229 - Knight Probability in Chessboard
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 4) return;
    const n = parseInt(input[0], 10);
    const numPorts = parseInt(input[1], 10);
    const maxBoxes = parseInt(input[2], 10);
    const maxWeight = parseInt(input[3], 10);
    let ptr = 4;
    const boxes = [];
    for (let i = 0; i < n; i++) {
        const port = parseInt(input[ptr++], 10);
        const w = parseInt(input[ptr++], 10);
        boxes.push([port, w]);
    }
    const dp = new Array(n + 1).fill(0);
    let trips = 2, lastPortChange = 0, weight = 0, j = 0;
    for (let i = 0; i < n; i++) {
        weight += boxes[i][1];
        if (i > 0 && boxes[i][0] !== boxes[i - 1][0]) {
            trips++;
            lastPortChange = i;
        }
        while (i - j + 1 > maxBoxes || weight > maxWeight || (j < i && dp[j] === dp[j + 1])) {
            weight -= boxes[j][1];
            if (boxes[j][0] !== boxes[j + 1][0]) trips--;
            j++;
        }
        dp[i + 1] = dp[j] + trips;
    }
    console.log(dp[n]);
}

main();
