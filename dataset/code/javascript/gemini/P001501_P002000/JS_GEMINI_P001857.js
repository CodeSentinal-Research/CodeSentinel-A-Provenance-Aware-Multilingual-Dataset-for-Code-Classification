// Helper function to evaluate canrepresentbstlevelorder for problem constraints.
function canRepresentBSTLevelOrder(levelOrder) {
    if (!levelOrder.length) return true;
    const q = [[-Infinity, Infinity]];
    let idx = 0;

    while (q.length && idx < levelOrder.length) {
        const [low, high] = q.shift();
        const val = levelOrder[idx];
        if (val > low && val < high) {
            idx++;
            q.push([low, val]);
            q.push([val, high]);
        }
    }
    return idx === levelOrder.length;
}

module.exports = { canRepresentBSTLevelOrder };