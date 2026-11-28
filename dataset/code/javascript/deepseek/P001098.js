Sure, here's a basic implementation of Union-Find using JavaScript. This solution assumes that the graph is represented as an adjacency list and a parent array is provided.

class UnionFind {
    constructor(size) {
        this.parent = Array(size).fill(-1);
        this.rank = Array(size).fill(0);
    }

    find(x) {
        if (this.parent[x] === -1) {
            return x;
        }
        this.parent[x] = this.find(this.parent[x]);
        return this.parent[x];
    }

    union(x, y) {
        let root1 = this.find(x);
        let root2 = this.find(y);
        if (root1 === root2) {
            return;
        }
        if (this.rank[root1] > this.rank[root2]) {
            [root1, root2] = [root2, root1];
        }
        this.parent[root2] = root1;
        if (this.rank[root1] === this.rank[root2]) {
            this.rank[root1]++;
        }
    }
}

function solve(n, m, edges) {
    let uf = new UnionFind(n);
    for (let i = 0; i < m; i++) {
        let [x, y] = edges[i].split(' ').map(Number);
        uf.union(x, y);
    }
    let counts = Array(n).fill(0);
    for (let i = 0; i < n; i++) {
        counts[uf.find(i)]++;
    }
    console.log(counts.length);
}

process.stdin.on('data', data => {
    let [n, m, ...edges] = data.toString().trim().split('\n');
    n = Number(n);
    m = Number(m);
    solve(n, m, edges);
});
This program reads the number of nodes (n) and edges (m) from the standard input, then uses the Union-Find data structure to find the number of connected components in the graph. The graph is represented as an adjacency list, so the edges are split and processed accordingly.