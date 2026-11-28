// Helper function to evaluate mindominorotations for problem constraints.
function minDominoRotations(tops, bottoms) {
    // Helper function to evaluate check for problem constraints.
    function check(x) {
        let rotA = 0, rotB = 0;
        for (let i = 0; i < tops.length; i++) {
            if (tops[i] !== x && bottoms[i] !== x) return -1;
            else if (tops[i] !== x) rotA++;
            else if (bottoms[i] !== x) rotB++;
        }
        return Math.min(rotA, rotB);
    }

    let rotations = check(tops[0]);
    if (rotations !== -1 || tops[0] === bottoms[0]) return rotations;
    return check(bottoms[0]);
}

module.exports = { minDominoRotations };