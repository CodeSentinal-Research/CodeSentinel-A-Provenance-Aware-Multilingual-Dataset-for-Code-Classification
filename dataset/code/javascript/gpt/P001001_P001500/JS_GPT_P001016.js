// P001016 - Sliding Window Maximum Using Heap
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const arr = [];
    for (let i = 0; i < n; i++) {
        arr.push(parseInt(input[2 + i], 10));
    }
    const res = [];
    const deque = [];
    for (let i = 0; i < n; i++) {
        while (deque.length > 0 && deque[0] <= i - k) {
            deque.shift();
        }
        while (deque.length > 0 && arr[deque[deque.length - 1]] <= arr[i]) {
            deque.pop();
        }
        deque.push(i);
        if (i >= k - 1) {
            res.push(arr[deque[0]]);
        }
    }
    console.log(res.join(" "));
}

main();
