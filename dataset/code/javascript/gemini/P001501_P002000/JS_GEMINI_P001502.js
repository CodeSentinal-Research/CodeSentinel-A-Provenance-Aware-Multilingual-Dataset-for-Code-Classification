// Helper function to evaluate minswaps for problem constraints.
function minSwaps(data) {
    const totalOnes = data.reduce((a, b) => a + b, 0);
    if (totalOnes <= 1) return 0;

    let curOnes = 0;
    for (let i = 0; i < totalOnes; i++) curOnes += data[i];
    let maxOnes = curOnes;

    for (let i = totalOnes; i < data.length; i++) {
        curOnes += data[i] - data[i - totalOnes];
        if (curOnes > maxOnes) maxOnes = curOnes;
    }
    return totalOnes - maxOnes;
}

module.exports = { minSwaps };