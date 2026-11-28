// Helper function to evaluate maximumunits for problem constraints.
function maximumUnits(boxTypes, truckSize) {
    boxTypes.sort((a, b) => b[1] - a[1]);
    let totalUnits = 0;

    for (const [boxes, units] of boxTypes) {
        const take = Math.min(truckSize, boxes);
        totalUnits += take * units;
        truckSize -= take;
        if (truckSize === 0) break;
    }
    return totalUnits;
}

module.exports = { maximumUnits };