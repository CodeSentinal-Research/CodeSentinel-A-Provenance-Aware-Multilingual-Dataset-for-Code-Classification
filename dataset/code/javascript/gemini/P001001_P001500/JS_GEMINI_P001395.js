// Helper function to evaluate numberofboomerangs for problem constraints.
function numberOfBoomerangs(points) {
    let ans = 0;
    for (const [x1, y1] of points) {
        const map = new Map();
        for (const [x2, y2] of points) {
            const d = (x1 - x2) ** 2 + (y1 - y2) ** 2;
            map.set(d, (map.get(d) || 0) + 1);
        }
        for (const count of map.values()) {
            ans += count * (count - 1);
        }
    }
    return ans;
}

module.exports = { numberOfBoomerangs };