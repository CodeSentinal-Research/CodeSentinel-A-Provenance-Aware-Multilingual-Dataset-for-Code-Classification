// Helper function to evaluate catchthieves for problem constraints.
function catchThieves(arr, k) {
    const police = [], thieves = [];
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] === 'P') police.push(i);
        else thieves.push(i);
    }

    let pIdx = 0, tIdx = 0, caught = 0;
    while (pIdx < police.length && tIdx < thieves.length) {
        if (Math.abs(police[pIdx] - thieves[tIdx]) <= k) {
            caught++;
            pIdx++;
            tIdx++;
        } else if (police[pIdx] < thieves[tIdx]) {
            pIdx++;
        } else {
            tIdx++;
        }
    }
    return caught;
}

module.exports = { catchThieves };