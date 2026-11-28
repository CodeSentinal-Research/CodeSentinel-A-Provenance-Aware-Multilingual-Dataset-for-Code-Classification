// Solves 'Count Diophantine Solutions in Range' by applying optimal Mathematics - Diophantine Equations logic.
function countDiophantineSolutions(a, b, c, minx, maxx, miny, maxy) {
    let count = 0;
    for (let x = minx; x <= maxx; x++) {
        const rem = c - a * x;
        if (rem % b === 0) {
            const y = rem / b;
            if (y >= miny && y <= maxy) count++;
        }
    }
    return count;
}

module.exports = { countDiophantineSolutions };