function solve() {
    let fs = require('fs');
    let input = fs.readFileSync('input.txt', 'utf8');
    let [N, M] = input.trim().split('\n').map(Number);
    let edges = [];
    for(let i = 0; i < M; i++) {
        let [u, v, w] = fs.readFileSync('input.txt', 'utf8').trim().split(' ').map(Number);
        edges.push([u, v, w]);
    }
    edges.sort((a, b) => a[2] - b[2]);
    let disjointSet = new Array(N + 1).fill(-1);
    let mst = [];
    let totalWeight = 0;
    for(let [u, v, w] of edges) {
        if(union(disjointSet, u, v) === false) continue;
        mst.push([u, v, w]);
        totalWeight += w;
    }
    console.log(totalWeight);

    function union(disjointSet, u, v) {
        u = find(disjointSet, u);
        v = find(disjointSet, v);
        if(u === v) return false;
        disjointSet[v] = u;
        return true;
    }

    function find(disjointSet, u) {
        if(disjointSet[u] !== u) disjointSet[u] = find(disjointSet, disjointSet[u]);
        return disjointSet[u];
    }
}
solve();

This script reads input from a file named `input.txt` and reads the file line by line. The first two numbers (N and M) are read from the first line of the file. The remaining lines each contain three numbers (u, v, w) which represent the edges in the graph. The edges are sorted by the weight in ascending order and for each edge, if the edge forms a cycle with the current MST, the edge is skipped. If the edge does not form a cycle with the current MST, the edge is added to the MST and the weight is added to the total weight. At the end, the total weight of the MST is printed. The `union` function is used to find the set of an element and the `find` function is used to find the root of the set.