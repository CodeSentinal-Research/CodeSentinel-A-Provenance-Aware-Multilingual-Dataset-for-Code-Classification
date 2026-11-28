function generateTrees(n) {
    if (n < 1) {
        return [];
    }

    const trees = new Map();

    function helper(start, end) {
        if (start > end) {
            return null;
        }

        if (start === end) {
            return new TreeNode(start);
        }

        const key = `${start}-${end}`;
        if (trees.has(key)) {
            return trees.get(key);
        }

        const tree = new TreeNode(start);

        tree.left = helper(start + 1, end);
        tree.right = helper(start, end - 1);

        trees.set(key, tree);

        return tree;
    }

    return helper(1, n);
}

class TreeNode {
    constructor(val = 0, left = null, right = null) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}