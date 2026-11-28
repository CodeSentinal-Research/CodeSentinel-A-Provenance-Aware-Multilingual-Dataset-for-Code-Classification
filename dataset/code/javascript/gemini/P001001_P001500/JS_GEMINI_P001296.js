// Helper function to evaluate earliestfullbloom for problem constraints.
function earliestFullBloom(plantTime, growTime) {
    const flowers = growTime.map((g, i) => [g, plantTime[i]]).sort((a, b) => b[0] - a[0]);
    let curPlantTime = 0, maxBloomTime = 0;

    for (const [grow, plant] of flowers) {
        curPlantTime += plant;
        maxBloomTime = Math.max(maxBloomTime, curPlantTime + grow);
    }
    return maxBloomTime;
}

module.exports = { earliestFullBloom };