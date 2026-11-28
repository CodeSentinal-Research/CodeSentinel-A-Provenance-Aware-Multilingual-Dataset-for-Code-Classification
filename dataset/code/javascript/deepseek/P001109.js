const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let N = 0;
let M = 0;
let graph = [];
let colors = [];

rl.on('line', (line) => {
  if (N === 0) {
    [N, M] = line.split(' ').map(Number);
    graph = Array.from({length: N}, () => []);
    colors = line.split(' ').map(Number);
  } else if (--M === 0) {
    const [u, v] = line.split(' ').map(Number);
    graph[u - 1].push(v - 1);
    graph[v - 1].push(u - 1);
  }
});

rl.on('close', () => {
  console.log(isValid() ? 'VALID' : 'INVALID');
  rl.close();
});

function isValid() {
  for (let u = 0; u < N; u++) {
    const neighbors = graph[u];
    const color = colors[u];
    for (let v of neighbors) {
      if (colors[v] === color) {
        return false;
      }
    }
  }
  return true;
}

This program reads the graph and coloring from standard input. It uses a depth-first search (DFS) to check if there are any adjacent vertices with the same color. If a vertex is visited and its color matches the current vertex's color, it means there's a cycle in the graph, and the coloring is not valid. If no such cycle is found, the coloring is valid.