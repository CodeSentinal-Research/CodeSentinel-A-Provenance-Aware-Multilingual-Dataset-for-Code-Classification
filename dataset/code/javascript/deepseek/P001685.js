function solve(input) {
    // Read input
    const [N, ...tree] = input.split('\n').map(s => s.trim()).map(Number);
    const nodes = tree.map(row => row.split(' ').map(Number));
    const target = Number(input.split('\n')[N]);

    // Initialize adjacency list
    const adjList = new Map();
    for (const [u, v] of nodes) {
        adjList.set(u, (adjList.get(u) || []).concat([v]));
        adjList.set(v, (adjList.get(v) || []).concat([u]));
    }

    // Breadth-first search to find target's nearest node
    const queue = [[target, null]];
    let nearest;
    while (queue.length) {
        const [node, parent] = queue.shift();
        if (nearest === undefined || (parent !== null && (nearest === null || adjList.get(nearest).indexOf(node) < adjList.get(node).indexOf(parent))) {
            nearest = node;
        }
        queue.push(...adjList.get(node).map(neighbor => [neighbor, node]));
    }

    // Print nearest node or 'None' if no such node exists
    console.log(nearest === null ? 'None' : nearest);
}

process.stdin.resume();
process.stdin.on('data', solve);
process.stdin.on('end', () => {
    process.stdout.write('\n');
    process.exit();
});