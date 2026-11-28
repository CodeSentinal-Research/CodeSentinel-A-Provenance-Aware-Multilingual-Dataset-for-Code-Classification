Here is a JavaScript solution for the problem:

const fs = require('fs');

const input = fs.readFileSync('input.txt', 'utf8');
const [V, E] = input.split('\n').map(Number);

const adjList = Array.from(Array(V), () => []);

const graph = Array.from(Array(E), () => []);

for (let i = 0; i < E; i++) {
  const [u, v] = fs.readFileSync('input.txt', 'utf8').split('\n')[i].split(' ').map(Number);
  graph[i] = [u, v];
  adjList[v].push(u);
}

const visited = Array(V).fill(false);

const paths = [];

function dfs(u, v, path) {
  path.push(u);
  if (u === v) {
    paths.push(path);
  } else {
    for (let i of adjList[u]) {
      if (!visited[i]) {
        visited[i] = true;
        dfs(i, v, path.slice());
        visited[i] = false;
      }
    }
  }
  path.pop();
}

visited[0] = true;
dfs(0, V - 1, []);

paths.sort();

for (let path of paths) {
  console.log(path.join(' '));
}

This code reads the graph from the input file. It uses depth-first search (DFS) to find all paths from the source to the target. It uses a visited array to track whether a node has been visited. The paths are sorted and printed to the console.

Please make sure to provide an input file with the given format. You can use the `input.txt` file provided in this response as an example.