// Helper function to evaluate countzerooutdegree for problem constraints.
function countZeroOutDegree(n, edges) {
    const outDegree = new Array(n).fill(0);
    for (const [u, v] of edges) outDegree[u]++;
    return outDegree.filter(d => d === 0).length;
}

module.exports = { countZeroOutDegree };