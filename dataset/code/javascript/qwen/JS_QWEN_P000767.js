const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const n = parseInt(input.trim());
    function genBST(start, end) {
        let res = [];
        if (start > end) { res.push(null); return res; }
        for (let i = start; i <= end; i++) {
            let leftTrees = genBST(start, i - 1);
            let rightTrees = genBST(i + 1, end);
            for (let l of leftTrees) {
                for (let r of rightTrees) {
                    let root = new TreeNode(i, l, r);
                    res.push(root);
                }
            }
        }
        return res;
    }
    class TreeNode {
        constructor(val, left, right) {
            this.val = val; this.left = left; this.right = right;
        }
    }
    // Serialization for output
    function serialize(root) {
        if (!root) return "null";
        return `${root.val}(${serialize(root.left)})(${serialize(root.right)})`;
    }
    let trees = genBST(1, n);
    console.log(trees.map(t => serialize(t)).join("\n"));
    rl.close();
});
