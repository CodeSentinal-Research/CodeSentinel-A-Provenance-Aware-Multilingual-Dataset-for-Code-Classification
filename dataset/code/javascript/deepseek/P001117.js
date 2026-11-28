Here is the JavaScript code that creates a deep copy of a directed graph:

// Reading input
const N = parseInt(readline());
const adjacencyList = [];
for (let i = 0; i < N; i++) {
    adjacencyList[i] = readline().split(' ').map(Number);
}

// Creating adjacency list for cloned graph
const clonedAdjacencyList = JSON.parse(JSON.stringify(adjacencyList));

// Printing the cloned graph
console.log(clonedAdjacencyList);

In this code, we first read the number of vertices (N) and the adjacency list for each vertex. We then create a deep copy of the adjacency list by converting the original adjacency list to a string using JSON.stringify(), and then converting the string back to an adjacency list using JSON.parse(). Finally, we print the cloned adjacency list.