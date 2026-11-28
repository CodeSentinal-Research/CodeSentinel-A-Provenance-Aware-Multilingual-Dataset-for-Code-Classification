function sqrtNewton(n, epsilon = 1e-7) {
    if (n < 0) throw new Error("Negative number");
    if (n === 0 || n === 1) return n;
    let x = n;
    while (true) {
        let root = 0.5 * (x + (n / x));
        if (Math.abs(root - x) < epsilon) {
            return root;
        }
        x = root;
    }
}

module.exports = { sqrtNewton };