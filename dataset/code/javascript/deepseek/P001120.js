// Create an object to store airports and their incoming edges.
let adjacencyList = new Map();

// Parse input and add edges to adjacency list.
function parseInput(input) {
  let [count, ...rest] = input.split('\n').map(Number);
  rest.forEach((edge) => {
    let [from, to] = edge.split(' ');
    if (!adjacencyList.has(from)) {
      adjacencyList.set(from, []);
    }
    adjacencyList.get(from).push(to);
  });
}

// DFS to find the starting point.
function findStartingPoint(start) {
  let stack = [start];
  while (stack.length) {
    let current = stack.pop();
    if (!adjacencyList.has(current)) {
      // If the current airport has no outgoing edges, add it to the result.
      res.push(current);
    } else {
      // If there are outgoing edges, add them to the stack.
      stack.push(current);
      adjacencyList.get(current).forEach((neighbor) => {
        stack.push(neighbor);
      });
    }
  }
}

// Topological sorting.
function solve() {
  // Find all the starting points.
  for (let [airport, edges] of adjacencyList.entries()) {
    if (edges.length === 0) {
      findStartingPoint(airport);
    }
  }
  // Reverse the result list and join all elements.
  res = res.reverse().join('');
  console.log(res);
}

let res = [];
parseInput(readline());
solve();