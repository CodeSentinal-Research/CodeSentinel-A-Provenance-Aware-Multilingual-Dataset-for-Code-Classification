// Helper function to evaluate verifythreaded for problem constraints.
function verifyThreaded(root) {
    if (!root) return true;
    let cur = root;
    while (cur.left) cur = cur.left;

    let count = 0;
    while (cur) {
        count++;
        if (cur.isThreaded) {
            cur = cur.right;
        } else {
            cur = cur.right;
            while (cur && cur.left) cur = cur.left;
        }
    }
    return count > 0;
}

module.exports = { verifyThreaded };