Here is the JavaScript code:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let inputs = [];

rl.on('line', function(line) {
  inputs.push(line);
}).on('close', function() {
  solve(inputs);
  process.exit();
});

function solve(inputs) {
  let [N, M, S] = inputs[0].split(' ').map(Number);
  let graph = Array.from({length: N}, () => new Array(N).fill(Infinity));
  let distances = Array.from({length: N}, () => Infinity);
  distances[S] = 0;

  for (let i = 0; i < M; i++) {
    let [u, v, w] = inputs[i + 1].split(' ').map(Number);
    graph[u - 1][v - 1] = w;
  }

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      for (let k = 0; k < N; k++) {
        if (distances[j] + graph[j][k] < distances[k]) {
          distances[k] = distances[j] + graph[j][k];
        }
      }
    }
  }

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      if (distances[j] + graph[j][i] < distances[i]) {
        console.log('NEGATIVE CYCLE');
        return;
      }
    }
  }

  console.log(distances.join(' '));
}

In this code, we read the number of vertices and edges from the input, then we read the edges and weights from the input. We initialize an array to keep track of the shortest distance from the source vertex to each other vertex. We then use the Bellman-Ford algorithm to update the shortest distances. If there is a negative weight cycle, we report it. Otherwise, we print the shortest distances.