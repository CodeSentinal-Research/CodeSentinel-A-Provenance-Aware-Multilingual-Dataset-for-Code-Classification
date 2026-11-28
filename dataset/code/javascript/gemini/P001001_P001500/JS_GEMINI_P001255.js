// Helper function to evaluate minaddtomakevalid for problem constraints.
function minAddToMakeValid(s) {
    let openNeeded = 0, closeNeeded = 0;
    for (const c of s) {
        if (c === '(') {
            closeNeeded++;
        } else {
            if (closeNeeded > 0) {
                closeNeeded--;
            } else {
                openNeeded++;
            }
        }
    }
    return openNeeded + closeNeeded;
}

module.exports = { minAddToMakeValid };