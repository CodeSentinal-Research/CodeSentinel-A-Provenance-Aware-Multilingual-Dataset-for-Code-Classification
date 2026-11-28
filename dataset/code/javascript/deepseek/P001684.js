function isCousins(root, x, y) {
    let queue = [root];
    let parent = { [root.val]: null };
    while (queue.length) {
        let node = queue.shift();
        if (node.left) {
            parent[node.left.val] = node;
            queue.push(node.left);
        }
        if (node.right) {
            parent[node.right.val] = node;
            queue.push(node.right);
        }
    }
    return parent[x] !== parent[y] && parent[x].val !== parent[y].val;
}