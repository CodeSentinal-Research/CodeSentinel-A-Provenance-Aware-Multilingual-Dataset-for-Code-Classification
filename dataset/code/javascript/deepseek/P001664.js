Here is the JavaScript code to check if a binary tree is perfect:

function solve(input) {
    const tree = {};
    tree.nodes = input.shift().split(' ');
    tree.children = {};
    for(let i=0; i<input.length; i++) {
        let nodes = input[i].split(' ');
        if(tree.children[nodes[0]] === undefined) {
            tree.children[nodes[0]] = [nodes[1], nodes[2]];
        } else {
            tree.children[nodes[0]].push(nodes[1]);
            tree.children[nodes[0]].push(nodes[2]);
        }
    }
    let depths = new Set();
    let queue = [{node: 'root', depth: 1}];
    while(queue.length > 0) {
        let current = queue.shift();
        depths.add(current.depth);
        if(tree.children[current.node]) {
            queue.push({node: tree.children[current.node][0], depth: current.depth + 1});
            queue.push({node: tree.children[current.node][1], depth: current.depth + 1});
        }
    }
    if(depths.size > 1 || (depths.size === 1 && !depths.has(1))) {
        console.log('NO');
    } else {
        console.log('YES');
    }
}

// Testing the solve function
let testInput1 = '5 root a b c d';
let testInput2 = '5 root a b c e f';
solve([testInput1, testInput2]);

In this code, we first define the tree structure as an object with children and nodes. We then create a queue and insert the root node into it with depth 1. We then enter a loop where we dequeue a node, check if there are children of the current node, and if so, enqueue them with the next depth level. The depth of all nodes is stored in a set to prevent duplicates and ensure perfectness. If any node has more than one child or if all nodes have the same depth, then the tree is not perfect. If the tree is perfect, we print 'YES' otherwise 'NO'.