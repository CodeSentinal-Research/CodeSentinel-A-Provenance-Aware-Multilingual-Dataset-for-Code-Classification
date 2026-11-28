Here is the JavaScript code for the given problem:

let readline = require('readline');

let rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let N = parseInt(rl.question(''));
let graph = new Map();

rl.on('line', (line) => {
  let [u, v] = line.split(' ');
  u = parseInt(u) - 1;
  v = parseInt(v) - 1;
  if (!graph.has(u)) graph.set(u, []);
  if (!graph.has(v)) graph.set(v, []);
  graph.get(u).push(v);
  graph.get(v).push(u);
  if (graph.size === N) {
    rl.close();
  }
});

function dfs(u, p) {
  let max1 = 0;
  let max2 = 0;
  let heights = new Array(N).fill(0);
  let heights_u = [u, p];
  let indexes = [0, 1];
  for (let i of graph.get(u)) {
    if (i === p) continue;
    let height = dfs(i, u) + 1;
    heights[height]++;
    if (height > max1) {
      [max1, max2] = [height, max1];
    } else if (height > max2) {
      max2 = height;
    }
    heights_u[indexes[0]] = height;
    indexes[1] = indexes[0];
    indexes[0] = i;
  }
  max1 = heights_u[max1];
  max2 = heights_u[max2];
  let diameter = max1 + max2;
  return Math.max(max1, max2) + 1;
}

console.log(Math.max(...new Array(N).fill(0)) - 1;

This code first reads the number of nodes (N) and then reads the edges. The graph is stored in a map where each node is a key, and its value is an array of its adjacent nodes. The dfs function is then called to find the diameter of the tree.

Please note that this code assumes that the input is from a file or standard input. If you are using this code in a file, you might need to adjust the input handling part according to your actual file or input source.