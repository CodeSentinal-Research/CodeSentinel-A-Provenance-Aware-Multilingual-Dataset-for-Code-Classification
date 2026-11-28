// Helper function to evaluate generatetrees for problem constraints.
function generateTrees(n) {
    if (n === 0) return [];

    // Helper function to evaluate build for problem constraints.
    function build(start, end) {
        if (start > end) return [null];
        const allTrees = [];
        for (let i = start; i <= end; i++) {
            const leftTrees = build(start, i - 1);
            const rightTrees = build(i + 1, end);
            for (const l of leftTrees) {
                for (const r of rightTrees) {
                    allTrees.push({ val: i, left: l, right: r });
                }
            }
        }
        return allTrees;
    }

    return build(1, n);
}

module.exports = { generateTrees };