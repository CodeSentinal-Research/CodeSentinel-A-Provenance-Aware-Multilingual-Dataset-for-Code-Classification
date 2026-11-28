Sure, here is the JavaScript solution:

// Initializing union-find data structure
let parent = new Array(100000).fill(-1).map((_, index) => index);

// Function to find the parent of a node
function find(node) {
    if (parent[node] !== -1) {
        if (parent[node] !== node) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }
    return node;
}

// Function to union two nodes
function union(node1, node2) {
    let parent1 = find(node1);
    let parent2 = find(node2);
    if (parent1 !== parent2) {
        parent[parent2] = parent1;
    }
}

// Function to solve the problem
function solve(n, queries) {
    for (let i = 0; i < queries.length; i++) {
        let [operation, node1, node2] = queries[i];
        if (operation === 1) {
            union(node1, node2);
        } else {
            let parent1 = find(node1);
            let parent2 = find(node2);
            if (parent1 === parent2) {
                console.log('YES');
            } else {
                console.log('NO');
            }
        }
    }
}

// Main function
function main() {
    let [n, q] = readline().split(' ');
    n = parseInt(n);
    q = parseInt(q);
    let queries = [];
    for (let i = 0; i < q; i++) {
        let [operation, node1, node2] = readline().split(' ');
        operation = parseInt(operation);
        node1 = parseInt(node1);
        node2 = parseInt(node2);
        queries.push([operation, node1, node2]);
    }
    solve(n, queries);
}

main();

In this code, we use union-find data structure to solve the connectivity problem efficiently. The union-find data structure is a specific data structure that maintains a partition of a set into disjoint subsets. In this case, each vertex in the graph is a node and each edge between two vertices is an operation.

The `main` function reads the input, calls the `solve` function with the input, and then reads the next set of queries.

The `solve` function takes a number of nodes and a list of queries, and performs each query based on the union-find data structure.

The `union` function connects two nodes in the graph, and the `find` function finds the parent of a node in the graph.

The `readline` function is a placeholder for a real implementation, which would read a line of input from the standard input.