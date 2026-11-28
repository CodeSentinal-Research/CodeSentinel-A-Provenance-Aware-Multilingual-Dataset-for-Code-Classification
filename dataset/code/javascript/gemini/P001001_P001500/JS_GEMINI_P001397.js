// Helper function to evaluate leastbricks for problem constraints.
function leastBricks(wall) {
    const map = new Map();
    let maxGaps = 0;

    for (const row of wall) {
        let edge = 0;
        for (let i = 0; i < row.length - 1; i++) {
            edge += row[i];
            const count = (map.get(edge) || 0) + 1;
            map.set(edge, count);
            if (count > maxGaps) maxGaps = count;
        }
    }
    return wall.length - maxGaps;
}

module.exports = { leastBricks };