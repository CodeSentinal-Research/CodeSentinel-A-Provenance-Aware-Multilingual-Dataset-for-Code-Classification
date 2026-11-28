Sure, here is a JavaScript solution using Union-Find algorithm.

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
    if (x === y) return false
    if (this.size[x] < this.size[y]) [x, y] = [y, x]
    this.parent[y] = x
    this.size[x] += this.size[y]
    return true
  }
}

function findRedundantConnection(edges) {
  const uf = new UnionFind(edges.length + 1)
  for (const edge of edges) {
    if (!uf.union(edge[0], edge[1])) {
      return edge
    }
  }
}

// example usage
const edges = [
  [1, 2],
  [1, 3],
  [2, 3],
]
console.log(findRedundantConnection(edges))  // [2, 3]

In this code, we first create a UnionFind class with a constructor that initializes the parent array and size array. The find method finds the root of a node, and the union method connects two nodes. If they are already connected, this will return false, otherwise it will connect them and return true.

In the `findRedundantConnection` function, we create a new UnionFind instance. We then iterate over the edges, and for each edge, we try to union them. If a redundant connection cannot be found after all edges are tried, this will return the redundant edge.

Please note that the input should be an array of arrays, where each inner array contains two integers representing the endpoints of an edge. The function will return the redundant edge as a pair of integers.