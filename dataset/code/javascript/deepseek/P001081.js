Here is the JavaScript code for the problem. This code uses Depth-First Search (DFS) to find whether the graph contains a Eulerian circuit or not. It is based on the idea that an Eulerian graph is a graph whose vertices can be visited twice and where every edge has a even degree.

class Graph {
  constructor(numVertices) {
    this.numVertices = numVertices;
    this.adjList = new Array(numVertices).fill(null).map(() => []);
  }

  addEdge(v, w) {
    this.adjList[v].push(w);
    this.adjList[w].push(v);
  }

  isCyclicUtil(v, visited, recStack) {
    visited[v] = true;
    recStack[v] = true;

    for (let neighbour of this.adjList[v]) {
      if (!visited[neighbour]) {
        if (this.isCyclicUtil(neighbour, visited, recStack)) {
          return true;
        } else if (recStack[neighbour]) {
          return true;
        }
      }
    }

    recStack[v] = false;
    return false;
  }

  isCyclic() {
    for (let i = 0; i < this.numVertices; i++) {
      if (this.isCyclicUtil(i, new Array(this.numVertices).fill(false), new Array(this.numVertices).fill(false))) {
        return true;
      }
    }
    return false;
  }
}

function solve() {
  let [N, M] = readline().split(' ').map(Number);
  let graph = new Graph(N);
  for (let i = 0; i < M; i++) {
    let [v, w] = readline().split(' ').map(Number);
    graph.addEdge(v - 1, w - 1);
  }

  if (graph.isCyclic()) {
    console.log('IMPOSSIBLE');
  } else {
    console.log('POSSIBLE');
  }
}

This code reads the number of vertices and edges from the input and creates a graph. It then calls the `isCyclic` method to check if the graph contains a Eulerian circuit. If the graph contains a Eulerian circuit, it prints 'POSSIBLE', otherwise it prints 'IMPOSSIBLE'.

Please note that this code assumes that the edges are provided in the format `<vertex 1> <vertex 2>`. Also, it assumes that the vertices are 1-indexed, meaning that the first vertex is 1, not 0.