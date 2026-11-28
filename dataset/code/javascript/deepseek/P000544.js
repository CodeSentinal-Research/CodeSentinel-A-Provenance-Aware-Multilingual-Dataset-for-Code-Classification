function openLock(deadends, target) {
    let queue = [['0000', 0]];
    const directions = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9'];
    const deadSet = new Set(deadends);
    let visited = new Set();
    
    while (queue.length) {
        let [node, step] = queue.shift();
        if (node === target) return step;
        if (visited.has(node)) continue;
        visited.add(node);
        for (let i = 0; i < 4; i++) {
            for (let dir of directions) {
                let newNode = node.slice(0, i) + dir + node.slice(i + 1, 4);
                if (deadSet.has(newNode)) continue;
                queue.push([newNode, step + 1]);
            }
        }
    }
    return -1;
}

// Use this function as following:
console.log(openLock(["0200", "0300", "0040"], "0001"));
In the above code, we are using a breadth-first search (BFS) approach to solve the problem. We start from the initial state "0000" and visit all nodes that can be reached by one step. We use a queue to do this. We also keep a visited set to track all nodes that we have visited. If a node is a deadend, we skip it.