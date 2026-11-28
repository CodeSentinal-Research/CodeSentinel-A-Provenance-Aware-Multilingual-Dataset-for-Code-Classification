// P001127 - Number of Provinces
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const parent = Array.from({ length: n }, (_, i) => i);
    function find(i) {
        if (parent[i] === i) return i;
        return parent[i] = find(parent[i]);
    }
    let provinces = n;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            const connected = parseInt(input[ptr++], 10);
            if (connected === 1 && i < j) {
                const ri = find(i), rj = find(j);
                if (ri !== rj) {
                    parent[ri] = rj;
                    provinces--;
                }
            }
        }
    }
    console.log(provinces);
}

main();
