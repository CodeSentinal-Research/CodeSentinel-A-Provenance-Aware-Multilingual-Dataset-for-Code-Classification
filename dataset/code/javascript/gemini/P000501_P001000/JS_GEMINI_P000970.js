// Helper function to evaluate tribonacci for problem constraints.
function tribonacci(n) {
    if (n === 0) return 0;
    if (n <= 2) return 1;
    let a = 0, b = 1, c = 1;
    for (let i = 3; i <= n; i++) {
        const next = a + b + c;
        a = b;
        b = c;
        c = next;
    }
    return c;
}

module.exports = { tribonacci };