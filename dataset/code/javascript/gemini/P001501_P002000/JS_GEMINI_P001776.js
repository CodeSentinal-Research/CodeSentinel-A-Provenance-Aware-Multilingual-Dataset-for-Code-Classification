// Helper function to evaluate iseverylevelpalindromic for problem constraints.
function isEveryLevelPalindromic(root) {
    if (!root) return true;
    const q = [root];

    while (q.length) {
        const size = q.length;
        const vals = [];
        for (let i = 0; i < size; i++) {
            const node = q.shift();
            vals.push(node.val);
            if (node.left) q.push(node.left);
            if (node.right) q.push(node.right);
        }
        for (let l = 0, r = size - 1; l < r; l++, r--) {
            if (vals[l] !== vals[r]) return false;
        }
    }
    return true;
}

module.exports = { isEveryLevelPalindromic };