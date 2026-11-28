// Helper function to evaluate findcousins for problem constraints.
function findCousins(root, targetVal) {
    if (!root || root.val === targetVal) return [];
    const q = [root];
    let found = false;

    while (q.length && !found) {
        const size = q.length;
        for (let i = 0; i < size; i++) {
            const cur = q.shift();
            if ((cur.left && cur.left.val === targetVal) || (cur.right && cur.right.val === targetVal)) {
                found = true;
            } else {
                if (cur.left) q.push(cur.left);
                if (cur.right) q.push(cur.right);
            }
        }
    }

    return found ? q.map(n => n.val) : [];
}

module.exports = { findCousins };