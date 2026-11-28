let graph = {};
let depth = {};
let parents = {};

function BFS(root) {
  let queue = [[root, 0]];
  while (queue.length) {
    let [node, d] = queue.shift();
    if (node !== depth[node]) {
      depth[node] = d;
      if (graph[node]) {
        graph[node].forEach(n => {
          if (depth[n] === undefined) {
            queue.push([n, d + 1]);
          }
        });
      }
    }
  }
}

function solve() {
  let [N, lines] = ['5', ['1', '2 3', '3', '4 2 4 5', '5']].map(s => s.trim());
  N = Number(N);
  let nodes = lines.map(s => s.split(' ').map(Number));
  let target = Number(lines[lines.length - 1]);
  for ([a, b] of nodes) {
    if (!graph[a]) graph[a] = [];
    graph[a].push(b);
    graph[b] = graph[b] || [];
    graph[b].push(a);
  }
  BFS(target);
  let res = [];
  graph[target].forEach(n => {
    res.push([n, depth[n] + depth[target]]);
  });
  res.sort((a, b) => a[1] - b[1]);
  console.log(res[0][0]);
}

solve();