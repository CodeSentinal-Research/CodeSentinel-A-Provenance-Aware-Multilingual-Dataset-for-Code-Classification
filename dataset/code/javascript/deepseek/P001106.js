const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of courses: ', (n) => {
  rl.question('Enter the number of prerequisite pairs: ', (m) => {
    const graph = Array.from({length: n + 1}, () => new Set());
    const indegree = Array.from({length: n + 1}, () => 0);
    const order = [];

    for (let i = 0; i < m; i++) {
      rl.question(`Enter pair ${i + 1}: `, (pair) => {
        const [a, b] = pair.split(' ');
        graph[a].add(b);
        indegree[b]++;
      });
   
    // add all nodes with zero indegree to the queue
    for (let i = 1; i <= n; i++) {
      if (indegree[i] === 0) {
        order.push(i);
      }
    }

    if (order.length === n) {
      console.log(order.join(' '));
    } else {
      console.log('IMPOSSIBLE');
    }

    rl.close();
  });
});
In this JavaScript code, we are using a simple graph theory approach where we use an adjacency list to represent the prerequisite relationships. Then we use a topological sort on the adjacency list. If there is a cycle in the graph, then there is no valid order, otherwise we can print the order.