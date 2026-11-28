function rotateMatrix(N, M, K, Mat) {
    const k = K % M;
    for (let i = 0; i < N; i++) {
        Mat[i] = Mat[i].slice(k).concat(Mat[i].slice(0, k));
    }
    return Mat;
}

module.exports = { rotateMatrix };