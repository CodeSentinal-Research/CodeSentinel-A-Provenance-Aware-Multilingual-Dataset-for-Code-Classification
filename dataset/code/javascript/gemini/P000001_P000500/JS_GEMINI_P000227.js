function maximumSumRectangle(R, C, M) {
    let maxSum = -Infinity;

    for (let l = 0; l < C; l++) {
        const temp = new Array(R).fill(0);
        for (let r = l; r < C; r++) {
            for (let i = 0; i < R; i++) {
                temp[i] += M[i][r];
            }

            let cur = temp[0], maxSoFar = temp[0];
            for (let i = 1; i < R; i++) {
                cur = Math.max(temp[i], cur + temp[i]);
                if (cur > maxSoFar) maxSoFar = cur;
            }

            if (maxSoFar > maxSum) maxSum = maxSoFar;
        }
    }
    return maxSum;
}

module.exports = { maximumSumRectangle };