// Helper function to evaluate reconstructqueue for problem constraints.
function reconstructQueue(people) {
    people.sort((a, b) => (a[0] === b[0]) ? a[1] - b[1] : b[0] - a[0]);
    const res = [];
    for (const p of people) {
        res.splice(p[1], 0, p);
    }
    return res;
}

module.exports = { reconstructQueue };