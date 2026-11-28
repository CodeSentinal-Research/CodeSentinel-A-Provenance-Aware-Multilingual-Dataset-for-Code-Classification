Sure, here is a simple solution using the JavaScript `Set` and `Map` data structures. The basic idea is to perform a topological sort on the graph, then count the connected components.

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of vertices and edges: ', (N, M) => {
  const graph = new Map();
  const visit = new Set();

  rl.setInterface({
    input: process.stdin,
    output: process.stdout
  });

  rl.question('Enter directed edges: ', (edges) => {
    edges.forEach(edge => {
      const [u, v] = edge.split(' ');
      if (!graph.has(u)) graph.set(u, []);
      graph.get(u).push(v);
    });

    const countComponents = () => {
      let count = 0;
      const dfs = (vertex, color) => {
        if (color[vertex]) return false;
        color[vertex] = true;
        if (!graph.get(vertex)) return true;
        for (const neighbour of graph.get(vertex)) {
          if (!dfs(neighbour, color)) return false;
        }
        return true;
      };

      for (let vertex of graph.keys()) {
        const color = {};
        if (dfs(vertex, color)) count++;
      }

      return count;
    };

    console.log(countComponents());

    rl.close();
  });
});

This program reads the number of vertices and edges, then reads the edges. After that, it calls the countComponents function and logs the result.

The countComponents function is a depth-first search (DFS) that counts the number of strongly connected components. It traverses each vertex in the graph and calls the DFS from that vertex. If it finds a vertex that is not visited in the DFS, it returns false. If it can visit all vertices in the DFS, it returns true. The count of strongly connected components is the number of times the DFS returns true.