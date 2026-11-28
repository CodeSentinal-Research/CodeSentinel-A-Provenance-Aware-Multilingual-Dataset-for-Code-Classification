Here is the JavaScript code that can solve the problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let inputs = [];

rl.on('line', function(line) {
  inputs.push(line);
}).on('close', function() {
  const [N, M, S, D, K] = inputs[0].split(' ').map(Number);
  const graph = Array.from(Array(N), () => Array(N).fill(Infinity));
  const costs = Array.from(Array(N), () => Array(K + 1).fill(Infinity));
  for (let i = 1; i <= M; i++) {
    const [u, v, cost] = inputs[i].split(' ').map(Number);
    graph[u][v] = cost;
    graph[v][u] = cost;
  }
  
  function solve(source, destination, k) {
    if (k < 0) return Infinity;
    if (k === 0) return (source === destination) ? 0 : Infinity;
    if (costs[source][k] !== Infinity) return costs[source][k];
    
    for (let i = 0; i < N; i++) {
      if (graph[source][i] !== Infinity) {
        const cost = graph[source][i] + solve(i, destination, k - 1);
        costs[source][k] = Math.min(costs[source][k], cost);
      }
    }
    return costs[source][k];
  }
  
  let result = solve(S, D, K);
  if (result === Infinity) {
    console.log(-1);
  } else {
    console.log(result);
  }
  
  rl.close();
});

This code uses a depth-first search (DFS) approach to find the minimum cost to travel from a source to a destination city using at most K stops. The graph is represented as an adjacency matrix where `graph[u][v]` represents the cost of travel from city u to city v. The `costs` array is used to store the minimum cost to travel from a source to a destination city with at most k stops.