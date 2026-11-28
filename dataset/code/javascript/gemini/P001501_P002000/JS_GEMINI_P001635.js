// Helper function to evaluate countequalzerosonessubmatrices for problem constraints.
function countEqualZerosOnesSubmatrices(mat) {
    const m = mat.length, n = mat[0].length;
    let ans = 0;

    for (let l = 0; l < n; l++) {
        const rowDiff = new Array(m).fill(0);
        for (let r = l; r < n; r++) {
            for (let i = 0; i < m; i++) rowDiff[i] += (mat[i][r] === 1 ? 1 : -1);

            const count = new Map();
            count.set(0, 1);
            let cur = 0;
            for (let i = 0; i < m; i++) {
                cur += rowDiff[i];
                ans += (count.get(cur) || 0);
                count.set(cur, (count.get(cur) || 0) + 1);
            }
        }
    }
    return ans;
}

module.exports = { countEqualZerosOnesSubmatrices };