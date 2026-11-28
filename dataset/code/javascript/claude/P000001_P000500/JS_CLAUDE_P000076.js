function findRoots(a, b, c) {
    const d = b * b - 4 * a * c;
    if (d > 0) {
        const r1 = (-b + Math.sqrt(d)) / (2 * a);
        const r2 = (-b - Math.sqrt(d)) / (2 * a);
        return [Math.max(r1, r2), Math.min(r1, r2)];
    } else if (d === 0) {
        const r = -b / (2 * a);
        return [r, r];
    }
    return [];
}

module.exports = { findRoots };
