Here is the JavaScript code to solve the problem:

function solve() {
  const fs = require('fs');
  const readline = require('readline');

  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
  });

  rl.on('line', (line) => {
    const [N, Q] = line.split(' ').map(Number);
    const tree = {};
    const queries = [];

    for (let i = 0; i < N - 1; i++) {
      const edge = readline.readline().split(' ').map(Number);
      if (!tree[edge[0]]) tree[edge[0]] = [];
      if (!tree[edge[1]]) tree[edge[1] ] = [];
      tree[edge[0]].push(edge[1]);
      tree[edge[1]].push(edge[0]);
    }

    rl.on('line', (line) => {
      const [u, v] = line.split(' ').map(Number);
      queries.push([u, v]);
      if (queries.length === Q) {
        rl.close();
        solveQueries(tree, queries);
      }
    });
  });

  function solveQueries(tree, queries) {
    for (let query of queries) {
      const [u, v] = query;
      console.log(findLCA(u, v, tree).join(' '));
    }
  }

  function findLCA(u, v, tree) {
    const cache = {};
    function dfs(node, parent) {
      if (cache[node]) return cache[node];
      if (node === u || node === v) return [node];
      for (let neighbor of tree[node]) {
        if (neighbor === parent) continue;
        const res = dfs(neighbor, node);
        if (res) return [node, ...res];
      }
      return [];
    }
    return dfs(u, null);
  }
}

solve();

In this code, we first read the input and construct a tree from the edges. Then, for each query, we find the Lowest Common Ancestor of the two nodes. This is done by performing a depth-first search on the tree, starting from the root node and moving to the other node. If a common ancestor is found, it is the Lowest Common Ancestor. If no common ancestor is found, an empty array is returned.