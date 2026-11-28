// Helper function to evaluate rankteams for problem constraints.
function rankTeams(votes) {
    const n = votes[0].length;
    const map = new Map();
    for (const c of votes[0]) map.set(c, new Array(n).fill(0));

    for (const v of votes) {
        for (let i = 0; i < n; i++) {
            map.get(v[i])[i]++;
        }
    }

    const list = Array.from(map.keys());
    list.sort((a, b) => {
        const cntA = map.get(a), cntB = map.get(b);
        for (let i = 0; i < n; i++) {
            if (cntA[i] !== cntB[i]) return cntB[i] - cntA[i];
        }
        return a.localeCompare(b);
    });

    return list.join('');
}

module.exports = { rankTeams };