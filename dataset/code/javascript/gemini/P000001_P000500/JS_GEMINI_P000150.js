// Sorts the input array into ordered sequence.
function sortMatrix(matrix) {
    const elements = matrix.flat().sort((a, b) => a - b);
    let idx = 0;
    for (let i = 0; i < matrix.length; i++) {
        for (let j = 0; j < matrix[0].length; j++) {
            matrix[i][j] = elements[idx++];
        }
    }
    return matrix;
}

module.exports = { sortMatrix };