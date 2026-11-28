Here is the JavaScript code for the problem:

let fs = require('fs');
let input = fs.readFileSync('input.txt', 'utf8');
input = input.split('\n');
let [N, M, S] = input[0].split(' ').map(Number);
let graph = {};
for (let i = 1; i < M + 1; i++) {
  let edge = input[i].split(' ').map(Number);
  if (!graph[edge[0]]) graph[edge[0]] = [];
  graph[edge[0]].push(edge[1]);
  if (!graph[edge[1]]) graph[edge[1]] = [];
  graph[edge[1]].push(edge[0]);
}

let visited = {};
let reachable = new Set();

function dfs(node) {
  if (visited[node]) return;
  visited[node] = true;
  if (graph[node]) {
    for (let neighbour of graph[node]) {
      if (!visited[neighbour]) {
        dfs(neighbour);
      }
    }
  }
  reachable.add(node);
}

dfs(S);
console.log(reachable.size - 1);

This code reads the input from a file named `input.txt`. The input file contains the number of vertices and edges in the graph, followed by the edges themselves. The `reachable` set is used to keep track of the reachable vertices. The `dfs` function is a Depth-First Search algorithm that visits each node in the graph. If a node is not visited, it is added to the reachable set and all of its unvisited neighbours are visited.