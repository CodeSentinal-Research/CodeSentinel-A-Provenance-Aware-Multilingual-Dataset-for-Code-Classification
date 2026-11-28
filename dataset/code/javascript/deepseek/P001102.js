Here is a basic JavaScript solution using the Kruskal's algorithm for finding the minimum spanning tree in a weighted graph:

class UnionFind {
    constructor(n) {
        this.parent = Array(n + 1).fill(null).map((_, i) => i)
        this.size = Array(n + 1).fill(1)
    }

    find(x) {
        if (this.parent[x] !== x) {
            this.parent[x] = this.find(this.parent[x])
        }
        return this.parent[x]
    }

    union(x, y) {
        x = this.find(x)
        y = this.find(y)
        if (x === y) {
            return false
        }
        if (this.size[x] < this.size[y]) {
            [x, y] = [y, x]
        }
        this.parent[y] = x
        this.size[x] += this.size[y]
        return true
    }
}

function solve(n, m, roads) {
    const uf = new UnionFind(n)
    let cost = 0
    let edges = []
    roads.forEach(([u, v, cost]) => {
        if (uf.union(u, v)) {
            edges.push([cost, u, v])
        }
    })
    if (edges.length < n - 1) {
        console.log(-1)
        return
    }
    edges.sort((a, b) => a[0] - b[0])
    for (let [cost, u, v] of edges) {
        if (uf.find(u) !== uf.find(v)) {
            cost += uf.size[uf.find(u)]
            uf.union(u, v)
        }
    }
    console.log(cost)
}

To use this code, you would call `solve` with the number of cities, the number of roads, and an array of road data. The road data should be an array with two elements for the cost of the road and two city indices. The `solve` function will print the minimum total construction cost if possible, or `-1` if not possible.

Here's an example of how you might use this code:

solve(3, 2, [[1, 2, 2], [2, 3, 3]])