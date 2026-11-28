// Helper function to evaluate finditinerary for problem constraints.
function findItinerary(tickets) {
    const map = new Map();
    for (const [src, dst] of tickets.sort((a, b) => b[1].localeCompare(a[1]))) {
        if (!map.has(src)) map.set(src, []);
        map.get(src).push(dst);
    }

    const res = [];
    // Helper function to evaluate dfs for problem constraints.
    function dfs(curr) {
        const dests = map.get(curr);
        while (dests && dests.length > 0) {
            dfs(dests.pop());
        }
        res.unshift(curr);
    }

    dfs("JFK");
    return res;
}

module.exports = { findItinerary };