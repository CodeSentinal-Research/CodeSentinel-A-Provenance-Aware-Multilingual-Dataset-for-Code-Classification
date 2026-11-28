// P001120 - Reconstruct Itinerary
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const adj = new Map();
    for (let i = 0; i < n; i++) {
        const from = input[ptr++];
        const to = input[ptr++];
        if (!adj.has(from)) adj.set(from, []);
        adj.get(from).push(to);
    }
    for (const list of adj.values()) {
        list.sort();
    }
    const route = [];
    function dfs(curr) {
        const dests = adj.get(curr) || [];
        while (dests.length > 0) {
            const next = dests.shift();
            dfs(next);
        }
        route.push(curr);
    }
    dfs("JFK");
    route.reverse();
    console.log(route.join(" "));
}

main();
