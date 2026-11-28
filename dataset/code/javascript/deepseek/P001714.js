Here is a JavaScript solution for the problem:

function countHalfNodes(n, edges) {
  // Create a graph from the edges
  var graph = {};
  for (var i = 0; i < n; i++) {
    var node = i + 1;
    graph[node] = [];
    var parent = edges[i].split(' ')[0];
    var child = edges[i].split(' ')[1];
    graph[parent].push(node);
    graph[node].push(parent);
  }

  // Count the nodes with one child
  var count = 0;
  for (var node in graph) {
    if (graph[node].length == 1) {
      count++;
    }
  }

  // Return the count
  return count;
}

This function first creates a graph from the input edges. Then it iterates over each node in the graph and checks if the node has only one child. If it does, it increments the count. Finally, it returns the count of half nodes.

However, this solution assumes that the input is a valid binary tree with `n` nodes and `n-1` edges. If the input is not a valid binary tree, this solution will not work correctly. You may need to adjust the code to handle these cases.