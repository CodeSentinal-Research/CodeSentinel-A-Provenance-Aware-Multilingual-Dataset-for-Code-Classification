// Sorts the input array into ordered sequence.
function sortedMatrix(N, Mat) {
    const flat = Mat.flat().sort((a, b) => a - b);
    let idx = 0;
    for (let i = 0; i < N; i++) {
        for (let j = 0; j < N; j++) {
            Mat[i][j] = flat[idx++];
        }
    }
    return Mat;
}

module.exports = { sortedMatrix };