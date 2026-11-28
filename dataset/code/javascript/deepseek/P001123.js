const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let [N, M, T] = rl.question('').split(' ').map(num => parseInt(num));
let graph = [];

for (let i = 0; i < M; i++) {
  let [u, v, w] = rl.question('').split(' ').map(num => parseInt(num));
  if (!graph[u]) graph[u] = [];
  graph[u][v] = w;
  graph[v][u] = w;
}

function bfs(start, end, threshold) {
  let distances = Array(N + 1).fill(Infinity);
  distances[start] = 0;
  let queue = [[start, 0]];

  while (queue.length) {
    let [node, dist] = queue.pop();
    if (node === end) return dist;

    for (let neighbor in graph[node]) {
      let neighborDist = dist + graph[node][neighbor];
      if (neighborDist < distances[neighbor]) {
        distances[neighbor] = neighborDist;
        queue.push([neighbor, neighborDist]);
      }
    }
  }

  return Infinity;
}

let minNeighbors = Infinity;
let minCity = -1;

for (let i = 1; i <= N; i++) {
  let neighbors = Object.keys(graph[i]).length;
  if (neighbors < minNeighbors) {
    minNeighbors = neighbors;
    minCity = i;
  }
}

console.log(minCity);
This code reads the graph from the standard input. It then uses a Breadth-First Search algorithm to find the city with the smallest number of reachable neighbors within a specified threshold distance. If multiple cities have the same smallest number of reachable neighbors, the largest city index is printed.