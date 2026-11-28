// P001055 - Minimum Refueling Stops
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const target = parseInt(input[0], 10);
    let startFuel = parseInt(input[1], 10);
    const n = parseInt(input[2], 10);
    let ptr = 3;
    const stations = [];
    for (let i = 0; i < n; i++) {
        const pos = parseInt(input[ptr++], 10);
        const fuel = parseInt(input[ptr++], 10);
        stations.push([pos, fuel]);
    }
    const maxHeap = [];
    let stops = 0;
    let prev = 0;
    stations.push([target, 0]);
    for (const [pos, fuel] of stations) {
        startFuel -= (pos - prev);
        while (startFuel < 0 && maxHeap.length > 0) {
            maxHeap.sort((a, b) => b - a);
            startFuel += maxHeap.shift();
            stops++;
        }
        if (startFuel < 0) {
            console.log(-1);
            return;
        }
        maxHeap.push(fuel);
        prev = pos;
    }
    console.log(stops);
}

main();
