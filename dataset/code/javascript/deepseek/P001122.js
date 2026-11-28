Here is a simple JavaScript solution that uses Depth-First Search (DFS) to solve the problem.

class Graph {
    constructor(numVertices) {
        this.numVertices = numVertices;
        this.adjList = new Map();
    }

    addEdge(v, w) {
        this.adjList.get(v).add(w);
    }

    dfsVisit(v, visited, recStack) {
        visited[v] = true;
        recStack[v] = true;

        for(let neighbor of this.adjList.get(v)) {
            if (!visited[neighbor] && this.dfsVisit(neighbor, visited, recStack)) {
                return true;
            } else if (recStack[neighbor]) {
                return true;
            }
        }

        recStack[v] = false;
        return false;
    }

    findSafeVertices() {
        let visited = new Array(this.numVertices).fill(false);
        let recStack = new Array(this.numVertices).fill(false);

        for (let v = 0; v < this.numVertices; v++) {
            if (!visited[v]) {
                if (this.dfsVisit(v, visited, recStack)) {
                    return;
                }
            }
        }

        for (let i = 0; i < visited.length; i++) {
            if (!visited[i]) {
                console.log(i);
            }
        }
    }
}

function solve(N, M, edges) {
    let g = new Graph(N);

    for (let edge of edges) {
        g.addEdge(edge[0], edge[1]);
    }

    g.findSafeVertices();
}
This solution assumes that the input edges are provided in an array of arrays, where each inner array contains two integers that represent the start and end vertices of an edge. The `solve` function takes these inputs and uses them to construct a graph, then calls `findSafeVertices` to print out all the vertices that can reach all other vertices from the start.

Please note that this code is a basic implementation and may not work correctly for large inputs due to limitations in JavaScript's performance. If you want to handle large inputs, you might need to use a more advanced data structure or algorithm.