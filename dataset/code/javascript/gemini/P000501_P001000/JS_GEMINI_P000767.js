const fs = require('fs');
class TreeNode {
    constructor(val, left = null, right = null) {
        this.val = val; this.left = left; this.right = right;
    }
}
function generateTrees(start, end) {
    if (start > end) return [null];
    const res = [];
    for (let i = start; i <= end; i++) {
        const leftTrees = generateTrees(start, i - 1);
        const rightTrees = generateTrees(i + 1, end);
        for (const l of leftTrees) {
            for (const r of rightTrees) {
                res.push(new TreeNode(i, l, r));
            }
        }
    }
    return res;
}
function serialize(root) {
    if (!root) return "null";
    return `${root.val}(${serialize(root.left)},${serialize(root.right)})`;
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const trees = generateTrees(1, parseInt(tokens[0], 10));
        for (const t of trees) console.log(serialize(t));
    }
}
main();