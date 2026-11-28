// P001299 - Minimum Time to Complete Trips
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const totalTrips = parseInt(input[1], 10);
    const times = [];
    for (let i = 0; i < n; i++) times.push(parseInt(input[2 + i], 10));
    let low = 1n, high = BigInt(Math.min(...times)) * BigInt(totalTrips);
    let ans = high;
    while (low <= high) {
        const mid = (low + high) / 2n;
        let trips = 0n;
        for (const t of times) {
            trips += mid / BigInt(t);
        }
        if (trips >= BigInt(totalTrips)) {
            ans = mid;
            high = mid - 1n;
        } else {
            low = mid + 1n;
        }
    }
    console.log(ans.toString());
}

main();
