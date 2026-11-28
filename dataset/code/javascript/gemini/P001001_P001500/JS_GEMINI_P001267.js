// Helper function to evaluate furthestbuilding for problem constraints.
function furthestBuilding(heights, bricks, ladders) {
    const pq = [];
    for (let i = 0; i < heights.length - 1; i++) {
        const diff = heights[i + 1] - heights[i];
        if (diff > 0) {
            let l = 0, r = pq.length;
            while (l < r) {
                const m = Math.floor((l + r) / 2);
                if (pq[m] < diff) l = m + 1;
                else r = m;
            }
            pq.splice(l, 0, diff);

            if (pq.length > ladders) {
                bricks -= pq.shift();
            }
            if (bricks < 0) return i;
        }
    }
    return heights.length - 1;
}

module.exports = { furthestBuilding };