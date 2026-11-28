// Helper function to evaluate countzeroindegree for problem constraints.
function countZeroInDegree(n, edges) {
    const inDegree = new Array(n).fill(0);
    for (const [u, v] of edges) inDegree[v]++;
    return inDegree.filter(d => d === 0).length;
}

module.exports = { countZeroInDegree };