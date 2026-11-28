// Helper function to evaluate numrabbits for problem constraints.
function numRabbits(answers) {
    const map = new Map();
    for (const a of answers) map.set(a, (map.get(a) || 0) + 1);

    let ans = 0;
    for (const [x, cnt] of map.entries()) {
        const groupSize = x + 1;
        const numGroups = Math.floor((cnt + groupSize - 1) / groupSize);
        ans += numGroups * groupSize;
    }
    return ans;
}

module.exports = { numRabbits };