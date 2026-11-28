const fs = require('fs');
const input = fs.readFileSync('input.txt', 'utf8');
const lines = input.split('\n');
const [N, M, S] = lines[0].split(' ').map(Number);
const edges = [];
for (let i = 1; i < M + 1; i++) {
  const [u, v, w] = lines[i].split(' ').map(Number);
  edges.push([u, v, w]);
}

class Graph {
  constructor(n) {
    this.graph = Array(n).fill(null).map(() => ({}));
  }

  addEdge(u, v, w) {
    this.graph[u][v] = w;
  }

  shortestPath(s) {
    const distances = Array(N).fill(Infinity);
    distances[s] = 0;
    const pq = [[0, s]];

    while (pq.length) {
      const [distU, u] = pq.pop();
      if (distU !== distances[u]) continue;

      for (const v in this.graph[u]) {
        const alt = distU + this.graph[u][v];
        if (alt < distances[Number(v)]) {
          distances[Number(v)] = alt;
          pq.push([alt, Number(v)]);
        }
      }
    }

    for (let i = 0; i < N; i++) {
      if (distances[i] === Infinity) {
        console.log('-1');
      } else {
        console.log(distances[i]);
      }
    }
  }
}

const graph = new Graph(N);
for (const [u, v, w] of edges) {
  graph.addEdge(u, v, w);
}
graph.shortestPath(S);