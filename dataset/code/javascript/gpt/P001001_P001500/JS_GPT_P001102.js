    // P001102 - Minimum Cost to Connect All Cities
    const fs = require("fs");

    function main() {
        const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
        if (!input || input.length < 2) return;
        const n = parseInt(input[0], 10);
        const m = parseInt(input[1], 10);
        let ptr = 2;
        const edges = [];
        for (let i = 0; i < m; i++) {
            const u = parseInt(input[ptr++], 10);
            const v = parseInt(input[ptr++], 10);
            const w = parseInt(input[ptr++], 10);
            edges.push({ u, v, w });
        }
        edges.sort((a, b) => a.w - b.w);
        const parent = Array.from({ length: n + 1 }, (_, i) => i);
        function find(i) {
            if (parent[i] === i) return i;
            return parent[i] = find(parent[i]);
        }
        let totalCost = 0;
        let count = 0;
        for (const e of edges) {
            const ru = find(e.u), rv = find(e.v);
            if (ru !== rv) {
                parent[ru] = rv;
                totalCost += e.w;
                count++;
            }
        }
        console.log(count === n - 1 ? totalCost : -1);
    }

    main();
