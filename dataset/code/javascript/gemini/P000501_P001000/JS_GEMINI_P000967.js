// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
function extGcd(a, b) {
    if (b === 0n) return [a, 1n, 0n];
    const [g, x1, y1] = extGcd(b, a % b);
    return [g, y1, x1 - (a / b) * y1];
}

// Helper function to evaluate earliesttimestamp for problem constraints.
function earliestTimestamp(mods, rems) {
    let a1 = BigInt(rems[0]), m1 = BigInt(mods[0]);
    for (let i = 1; i < mods.length; i++) {
        const a2 = BigInt(rems[i]), m2 = BigInt(mods[i]);
        const [g, p] = extGcd(m1, m2);
        if ((a2 - a1) % g !== 0n) return -1;
        const mod = (m1 / g) * m2;
        const step = (a2 - a1) / g;
        const k = (p * step) % (m2 / g);
        a1 = (a1 + k * m1) % mod;
        m1 = mod;
    }
    return Number(((a1 % m1) + m1) % m1);
}

module.exports = { earliestTimestamp };