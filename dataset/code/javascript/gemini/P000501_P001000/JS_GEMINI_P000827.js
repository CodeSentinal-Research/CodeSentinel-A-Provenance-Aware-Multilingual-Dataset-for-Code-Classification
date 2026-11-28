function findRadius(houses, heaters) {
    houses.sort((a, b) => a - b);
    heaters.sort((a, b) => a - b);
    let maxR = 0;
    let i = 0;
    for (const h of houses) {
        while (i + 1 < heaters.length && Math.abs(heaters[i + 1] - h) <= Math.abs(heaters[i] - h)) {
            i++;
        }
        maxR = Math.max(maxR, Math.abs(heaters[i] - h));
    }
    return maxR;
}

module.exports = { findRadius };