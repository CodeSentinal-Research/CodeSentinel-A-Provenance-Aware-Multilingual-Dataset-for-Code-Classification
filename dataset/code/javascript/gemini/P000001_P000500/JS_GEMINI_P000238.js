// Sorts the input array into ordered sequence.
function isOrthogonal(matrix, n) {
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            let dot = 0;
            for (let k = 0; k < n; k++) {
                dot += matrix[i][k] * matrix[j][k];
            }
            if (i === j && dot !== 1) return false;
            if (i !== j && dot !== 0) return false;
        }
    }
    return true;
}

module.exports = { isOrthogonal };