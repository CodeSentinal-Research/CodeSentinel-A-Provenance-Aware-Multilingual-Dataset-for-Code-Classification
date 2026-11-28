// Helper function to evaluate mincostcutboard for problem constraints.
function minCostCutBoard(x, y) {
    x.sort((a, b) => b - a);
    y.sort((a, b) => b - a);

    let hPieces = 1n, vPieces = 1n, totalCost = 0n;
    let i = 0, j = 0;

    while (i < x.length && j < y.length) {
        if (x[i] >= y[j]) {
            totalCost += BigInt(x[i]) * vPieces;
            hPieces++;
            i++;
        } else {
            totalCost += BigInt(y[j]) * hPieces;
            vPieces++;
            j++;
        }
    }
    while (i < x.length) {
        totalCost += BigInt(x[i]) * vPieces;
        i++;
    }
    while (j < y.length) {
        totalCost += BigInt(y[j]) * hPieces;
        j++;
    }

    return Number(totalCost);
}

module.exports = { minCostCutBoard };