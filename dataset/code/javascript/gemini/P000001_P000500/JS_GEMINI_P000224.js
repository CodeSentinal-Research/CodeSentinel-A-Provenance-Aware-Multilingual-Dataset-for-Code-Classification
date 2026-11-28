function JobScheduling(arr, n) {
    arr.sort((a, b) => b.profit - a.profit);
    let maxD = 0;
    for (const j of arr) if (j.deadline > maxD) maxD = j.deadline;

    const slot = new Array(maxD + 1).fill(-1);
    let count = 0, totalProfit = 0;

    for (const j of arr) {
        for (let d = j.deadline; d > 0; d--) {
            if (slot[d] === -1) {
                slot[d] = j.id;
                count++;
                totalProfit += j.profit;
                break;
            }
        }
    }
    return [count, totalProfit];
}

module.exports = { JobScheduling };