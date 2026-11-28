Here is the JavaScript code for finding all articulation points in a connected undirected graph:

function solve() {
  var fs = require('fs');
  var input = fs.readFileSync('input.txt', 'utf8');
  var lines = input.split('\n');
  var N = parseInt(lines[0]);
  var M = parseInt(lines[1]);
  var edges = [];
  for (var i = 2; i < lines.length; i++) {
    edges.push(parseInt(lines[i]));
  }
  var graph = Array(N + 1).fill(null).map((_, i) => ({}));
  for (var i = 0; i < M; i++) {
    var [u, v] = [edges[2 * i], edges[2 * i + 1]];
    if (!graph[u][v]) graph[u][v] = 1, graph[v][u] = 1;
  }
  var articulationPoints = [];
  function dfs(node, parent) {
    var count = 0;
    var children = 0;
    for (var neighbor in graph[node]) {
      if (neighbor == parent) continue;
      var child = graph[node][neighbor];
      count += dfs(child, node);
      children++;
    }
    if (children > 1) {
      articulationPoints.push(node);
    }
    return count + 1;
  }
  articulationPoints.length = 0;
  dfs(1);
  if (articulationPoints.length == 0) {
    console.log('NONE');
  } else {
    articulationPoints.sort((a, b) => a - b);
    console.log(articulationPoints.join(' '));
  }
}
solve();

This code uses depth-first search to find all articulation points. It first reads the graph from the input file, then it uses DFS to find the articulation points. The articulation points are stored in an array and then printed in ascending order.