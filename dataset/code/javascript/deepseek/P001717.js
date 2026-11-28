function solve(tree) {
    let count = 0;

    function dfs(node, path = '') {
        if (!node) return;

        const newPath = path + node.value;

        if (!node.left && !node.right) {
            count++;
            console.log(newPath);
            return;
        }

        dfs(node.left, newPath);
        dfs(node.right, newPath);
    }

    dfs(tree);

    console.log(count);
}

// for example usage
const tree = { value: 'root', left: { value: 'left', left: { value: 'left.left' }, right: { value: 'left.right' } }, right: { value: 'right', left: { value: 'right.left' }, right: { value: 'right.right' } } };
solve(tree);