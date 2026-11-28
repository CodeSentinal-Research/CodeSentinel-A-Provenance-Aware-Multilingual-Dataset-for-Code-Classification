// P001300 - Minimum Number of Rescue Boats with Variable Capacity
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const limit = parseInt(input[1], 10);
    const people = [];
    for (let i = 0; i < n; i++) people.push(parseInt(input[2 + i], 10));
    people.sort((a, b) => a - b);
    let l = 0, r = n - 1, boats = 0;
    while (l <= r) {
        if (people[l] + people[r] <= limit) {
            l++;
        }
        r--;
        boats++;
    }
    console.log(boats);
}

main();
