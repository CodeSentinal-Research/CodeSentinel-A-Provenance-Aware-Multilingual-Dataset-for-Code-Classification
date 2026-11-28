// Helper function to evaluate phi1ton for problem constraints.
function phi1ToN(n) {
    const phi = new Int32Array(n + 1);
    for (let i = 0; i <= n; i++) phi[i] = i;
    for (let i = 2; i <= n; i++) {
        if (phi[i] === i) {
            for (let j = i; j <= n; j += i) {
                phi[j] -= Math.floor(phi[j] / i);
            }
        }
    }
    return Array.from(phi.subarray(1));
}

module.exports = { phi1ToN };