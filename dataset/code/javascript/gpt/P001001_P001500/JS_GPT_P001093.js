// P001093 - Check Graph Isomorphism
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    let ptr = 2;
    const deg1 = new Array(n).fill(0);
    for (let i = 0; i < m; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        deg1[u]++;
        deg1[v]++;
    }
    const n2 = parseInt(input[ptr++], 10);
    const m2 = parseInt(input[ptr++], 10);
    if (n !== n2 || m !== m2) {
        console.log("NO");
        return;
    }
    const deg2 = new Array(n2).fill(0);
    for (let i = 0; i < m2; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        deg2[u]++;
        deg2[v]++;
    }
    deg1.sort((a, b) => a - b);
    deg2.sort((a, b) => a - b);
    for (let i = 0; i < n; i++) {
        if (deg1[i] !== deg2[i]) {
            console.log("NO");
            return;
        }
    }
    console.log("YES");
}

main();
