Here is a JavaScript solution for the given problem using Union-Find data structure. The Union-Find data structure is a data structure that is used to manage a set of elements partitioned into a number of disjoint sets.

class UnionFind {
    constructor(size) {
        this.parent = Array(size).fill(null).map((_, index) => index)
        this.size = Array(size).fill(1)
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
        if (x !== y) {
            this.parent[y] = x
            this.size[x] += this.size[y]
        }
    }
}

function solve(n, m, edges) {
    let unionFind = new UnionFind(n)
    for (let [u, v] of edges) {
        unionFind.union(u, v)
    }

    let root = unionFind.find(0)
    for (let i = 1; i < n; i++) {
        if (unionFind.find(i) !== root) {
            return 'NO'
        }
    }
    return 'YES'
}

function main() {
    const [n, m] = readline().split(' ').map(Number)
    let edges = []
    for (let i = 0; i < m; i++) {
        const [u, v] = readline().split(' ').map(Number)
        edges.push([u, v])
    }
    console.log(solve(n, m, edges))
}

function readline() {
    return process.stdin.readline()
}

main()

This code first declares the UnionFind class. The union operation finds the roots of the two sets of x and y, and then unions the roots into one. The find operation simply returns the root of the set that x belongs to.

In the main function, it reads the number of vertices and edges from the input, and then reads the edges. The solve function checks if the graph forms a tree by using the UnionFind data structure.

Please note that this code does not include any error handling or input validation. You might want to add these if your actual implementation requires.