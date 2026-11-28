Here is a JavaScript solution using Kruskal's algorithm for finding the Minimum Spanning Tree in an undirected graph:

class UnionFind {
    constructor(n) {
        this.parent = new Array(n);
        this.size = new Array(n).fill(-1);
        for(let i = 0; i < n; i++) {
            this.parent[i] = i;
        }
    }

    find(x) {
        if(this.parent[x] != x) {
            this.parent[x] = this.find(this.parent[x]);
        }
        return this.parent[x];
    }

    union(x, y) {
        x = this.find(x);
        y = this.find(y);
        if(x != y) {
            if(this.size[x] < this.size[y]) {
                let temp = x;
                x = y;
                y = temp;
            }
            this.parent[y] = x;
            this.size[x] += this.size[y];
        }
    }
}

function solve(N, M, edges) {
    let unionFind = new UnionFind(N);
    let totalWeight = 0;
    for(let i = 0; i < M; i++) {
        let [u, v, w] = edges[i];
        totalWeight += w;
        unionFind.union(u, v);
    }
    return totalWeight;
}

process.stdin.on('data', (data) => {
    let [N, M] = data.split(' ').map(Number);
    let edges = [];
    for(let i = 0; i < M; i++) {
        let [u, v, w] = process.stdin.readLine().split(' ').map(Number);
        edges.push([u, v, w]);
    }
    console.log(solve(N, M, edges));
});

This code defines a `UnionFind` class that implements the Union-Find data structure, and a `solve` function that takes the number of nodes and edges as input, and returns the total weight of the Minimum Spanning Tree.

The `solve` function uses Kruskal's algorithm to find the Minimum Spanning Tree. It initializes a `UnionFind` with the number of nodes, and then iterates over the edges of the graph. For each edge, it adds the weight to the total weight and adds the edge to the UnionFind. Finally, it returns the total weight.

The code reads the input from stdin, and then calls `solve` with the number of nodes and edges. It then logs the result to stdout.

This code assumes that the graph is connected and that the graph is undirected.