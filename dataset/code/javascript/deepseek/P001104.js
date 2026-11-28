Here is a simple JavaScript solution using a graph data structure and an adjacency list representation. 

function cloneGraph(node) {
    if (node === null) return null;
    let copiedNodes = {};
    let queue = [node];
    
    copiedNodes[node.val] = new Node(node.val);
    
    while (queue.length) {
        let currentNode = queue.shift();
        for (let neighbour of currentNode.neighbors) {
            if (!copiedNodes[neighbour.val]) {
                copiedNodes[neighbour.val] = new Node(neighbour.val);
                copiedNodes[currentNode.val].neighbors.push(copiedNodes[neighbour.val]);
                queue.push(neighbour);
            } else {
                copiedNodes[currentNode.val].neighbors.push(copiedNodes[neighbour.val]);
            }
        }
    }
    return copiedNodes[node.val];
}

This function takes a node as input and clones the graph. It uses a depth-first search (DFS) approach to visit all the nodes. For each node, it creates a new node with the same value and adds it to the `copiedNodes` object. It also adds the new node to the neighbors of the old node. 

It also uses a queue to implement the DFS traversal. The queue is initially filled with the original node. When a node is dequeued, all its neighbors are dequeued and added to the `copiedNodes` object and the queue. This process repeats until all nodes have been visited.