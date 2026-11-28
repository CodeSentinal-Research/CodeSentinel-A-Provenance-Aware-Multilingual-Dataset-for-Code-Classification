// Helper function to evaluate largestsmaller for problem constraints.
function largestSmaller(root, key) {
    let ans = -1;
    let cur = root;

    while (cur) {
        if (cur.val < key) {
            ans = cur.val;
            cur = cur.right;
        } else {
            cur = cur.left;
        }
    }
    return ans;
}

module.exports = { largestSmaller };