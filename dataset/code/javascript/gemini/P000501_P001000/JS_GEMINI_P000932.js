// Helper function to evaluate matrixtrace for problem constraints.
function matrixTrace(mat) {
    let trace = 0;
    for (let i = 0; i < mat.length; i++) {
        trace += mat[i][i];
    }
    return trace;
}

module.exports = { matrixTrace };