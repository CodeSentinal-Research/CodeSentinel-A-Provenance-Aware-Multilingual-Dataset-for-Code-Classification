// Generate All Unique Binary Search Trees
const fs = require("fs");
const _stdin_all = fs.readFileSync(0, "utf8");
let _stdin_tokens = _stdin_all.trim() ? _stdin_all.trim().split(/\s+/) : [];
let _stdin_ptr = 0;
function _stdin_next() { return _stdin_tokens[_stdin_ptr++]; }
class TreeNode {
    constructor(val, left, right) {
        self.val = val;
        self.left = left;
        self.right = right;
    }
}
function generate_trees(start, end) {
    if (start > end) {
        return [null];
    }
    let all_trees = [];
    for (const i of Array.from({length: ((end + 1)) - (start)}, (_, i) => (start) + i)) {
        let left_trees = generate_trees(start, (i - 1));
        let right_trees = generate_trees((i + 1), end);
        for (const l of left_trees) {
            for (const r of right_trees) {
                all_trees.push(TreeNode(i, l, r));
            }
        }
    }
    return all_trees;
}
function serialize(root) {
    if (!(root)) {
        return "null";
    }
    return `${root.val}(${serialize(root.left)},${serialize(root.right)})`;
}
function main() {
    let tokens = _stdin_all.trim().split(/\s+/);
    if (tokens) {
        let n = parseInt(tokens[0], 10);
        let trees = generate_trees(1, n);
        for (const t of trees) {
            console.log(serialize(t));
        }
    }
}
main();
