// P001247 - Advantage Shuffle
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const arr = [], dep = [];
    for (let i = 0; i < n; i++) arr.push(parseInt(input[ptr++], 10));
    for (let i = 0; i < n; i++) dep.push(parseInt(input[ptr++], 10));
    arr.sort((a, b) => a - b);
    dep.sort((a, b) => a - b);
    let platNeeded = 0, maxPlat = 0, i = 0, j = 0;
    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platNeeded++;
            maxPlat = Math.max(maxPlat, platNeeded);
            i++;
        } else {
            platNeeded--;
            j++;
        }
    }
    console.log(maxPlat);
}

main();
