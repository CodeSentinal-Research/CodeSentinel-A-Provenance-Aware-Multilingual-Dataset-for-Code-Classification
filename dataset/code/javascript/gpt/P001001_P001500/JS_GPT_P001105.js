// P001105 - Course Schedule
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const numCourses = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    let ptr = 2;
    const adj = Array.from({ length: numCourses }, () => []);
    const inDegree = new Array(numCourses).fill(0);
    for (let i = 0; i < m; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        adj[v].push(u);
        inDegree[u]++;
    }
    const queue = [];
    for (let i = 0; i < numCourses; i++) {
        if (inDegree[i] === 0) queue.push(i);
    }
    let count = 0;
    while (queue.length > 0) {
        const u = queue.shift();
        count++;
        for (const v of adj[u]) {
            inDegree[v]--;
            if (inDegree[v] === 0) queue.push(v);
        }
    }
    console.log(count === numCourses ? "YES" : "NO");
}

main();
