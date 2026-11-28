// P001008 - Insert an Element into a Min Heap
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const val = parseInt(input[1], 10);
    const arr = [];
    for (let i = 0; i < n; i++) {
        arr.push(parseInt(input[2 + i], 10));
    }
    arr.push(val);
    let i = arr.length - 1;
    while (i > 0) {
        const p = Math.floor((i - 1) / 2);
        if (arr[p] > arr[i]) {
            const temp = arr[i];
            arr[i] = arr[p];
            arr[p] = temp;
            i = p;
        } else {
            break;
        }
    }
    console.log(arr.join(" "));
}

main();
