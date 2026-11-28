// P001484 - Longest Mountain in Array
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const arr = [];
    for (let i = 0; i < n; i++) arr.push(parseInt(input[1 + i], 10));
    let maxMountain = 0;
    let i = 1;
    while (i < n - 1) {
        const isPeak = arr[i - 1] < arr[i] && arr[i] > arr[i + 1];
        if (!isPeak) {
            i++;
            continue;
        }
        let l = i - 1;
        while (l > 0 && arr[l - 1] < arr[l]) l--;
        let r = i + 1;
        while (r < n - 1 && arr[r + 1] < arr[r]) r++;
        maxMountain = Math.max(maxMountain, r - l + 1);
        i = r;
    }
    console.log(maxMountain);
}

main();
