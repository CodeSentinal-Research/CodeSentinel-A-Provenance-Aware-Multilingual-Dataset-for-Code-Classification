// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
function extGcd(a, b) {
    if (b === 0) return [a, 1, 0];
    const [g, x1, y1] = extGcd(b, a % b);
    return [g, y1, x1 - Math.floor(a / b) * y1];
}

// Solves 'Linear Congruence Solver' by applying optimal Mathematics - Extended Euclidean Algorithm logic.
function solveCongruence(a, b, m) {
    const [g, x] = extGcd(a, m);
    if (b % g !== 0) return [];
    let x0 = (x * Math.floor(b / g)) % m;
    x0 = (x0 + m) % m;
    const step = Math.floor(m / g);
    const ans = [];
    for (let i = 0; i < g; i++) {
        ans.push((x0 + i * step) % m);
    }
    return ans.sort((u, v) => u - v);
}

module.exports = { solveCongruence };