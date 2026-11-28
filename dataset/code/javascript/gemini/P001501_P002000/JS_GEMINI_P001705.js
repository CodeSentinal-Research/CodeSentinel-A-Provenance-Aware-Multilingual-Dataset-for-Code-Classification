// Helper function to evaluate widthofbinarytree for problem constraints.
function widthOfBinaryTree(root) {
    if (!root) return 0;
    const queue = [[root, 0n]];
    let maxWidth = 0n;

    while (queue.length) {
        const size = queue.length;
        const minIdx = queue[0][1];
        let first = 0n, last = 0n;

        for (let i = 0; i < size; i++) {
            const [node, idx] = queue.shift();
            const curIdx = idx - minIdx;
            if (i === 0) first = curIdx;
            if (i === size - 1) last = curIdx;

            if (node.left) queue.push([node.left, 2n * curIdx]);
            if (node.right) queue.push([node.right, 2n * curIdx + 1n]);
        }
        const width = last - first + 1n;
        if (width > maxWidth) maxWidth = width;
    }
    return Number(maxWidth);
}

module.exports = { widthOfBinaryTree };