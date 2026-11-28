function findCommonElements(mat) {
    if (!mat.length) return [];
    let common = new Set(mat[0]);

    for (let i = 1; i < mat.length; i++) {
        const rowSet = new Set(mat[i]);
        common = new Set([...common].filter(x => rowSet.has(x)));
    }

    return Array.from(common).sort((a, b) => a - b);
}

module.exports = { findCommonElements };