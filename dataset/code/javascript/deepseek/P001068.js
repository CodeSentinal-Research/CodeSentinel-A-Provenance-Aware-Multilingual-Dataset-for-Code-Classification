class Graph {
  constructor() {
    this.adjacencyList = {};
  }

  addVertex(vertex) {
    if (!(vertex in this.adjacencyList)) {
      this.adjacencyList[vertex] = [];
    }
  }

  addEdge(vertex1, vertex2) {
    this.adjacencyList[vertex1].push(vertex2);
  }

  topologicalSortHelper(vertex, visited, stack) {
    visited[vertex] = true;

    for (let i = 0; i < this.adjacencyList[vertex].length; i++) {
      let neighbour = this.adjacencyList[vertex][i];
      if (!visited[neighbour]) {
        this.topologicalSortHelper(neighbour, visited, stack);
      }
    }

    stack.push(vertex);
  }

  topologicalSort() {
    let visited = {};
    let stack = [];

    for (let vertex in this.adjacencyList) {
      if (!visited[vertex]) {
        this.topologicalSortHelper(vertex, visited, stack);
      }
    }

    return stack;
  }
}

let graph = new Graph();
let inputs = process.argv.slice(2);
let N = parseInt(inputs[0]);
let M = parseInt(inputs[1]);

for (let i = 0; i < N; i++) {
  graph.addVertex(i);
}

for (let i = 0; i < M; i++) {
  let [vertex1, vertex2] = inputs[i + 2].split(' ');
  graph.addEdge(parseInt(vertex1), parseInt(vertex2));
}

let result = graph.topologicalSort();

if (result.length === N) {
  console.log(result.join(' '));
} else {
  console.log('IMPOSSIBLE');
}