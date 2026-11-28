// Helper function to evaluate jobsequencing for problem constraints.
function jobSequencing(deadlines, profits) {
    const jobs = deadlines.map((d, i) => [d, profits[i]]).sort((a, b) => b[1] - a[1]);
    const maxD = Math.max(...deadlines);
    const slots = new Array(maxD + 1).fill(-1);
    let count = 0, totalProfit = 0;

    for (const [d, p] of jobs) {
        for (let j = d; j > 0; j--) {
            if (slots[j] === -1) {
                slots[j] = p;
                count++;
                totalProfit += p;
                break;
            }
        }
    }
    return [count, totalProfit];
}

module.exports = { jobSequencing };