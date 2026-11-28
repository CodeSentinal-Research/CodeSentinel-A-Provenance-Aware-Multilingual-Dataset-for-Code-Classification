// Helper function to evaluate furthestbuilding for problem constraints.
function furthestBuilding(heights, bricks, ladders) {
    const climbs = [];
    for (let i = 0; i < heights.length - 1; i++) {
        const diff = heights[i + 1] - heights[i];
        if (diff > 0) {
            let l = 0, r = climbs.length;
            while (l < r) {
                // Calculate midpoint to prevent potential overflow
                const mid = Math.floor((l + r) / 2);
                if (climbs[mid] < diff) l = mid + 1;
                else r = mid;
            }
            climbs.splice(l, 0, diff);
            if (climbs.length > ladders) {
                bricks -= climbs.shift();
                if (bricks < 0) return i;
            }
        }
    }
    return heights.length - 1;
}

module.exports = { furthestBuilding };