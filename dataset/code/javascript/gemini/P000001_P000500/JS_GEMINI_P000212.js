function canPlaceFlowers(flowerbed, n) {
    let count = 0;
    const len = flowerbed.length;
    for (let i = 0; i < len; i++) {
        if (flowerbed[i] === 0) {
            const emptyLeft = i === 0 || flowerbed[i - 1] === 0;
            const emptyRight = i === len - 1 || flowerbed[i + 1] === 0;
            if (emptyLeft && emptyRight) {
                flowerbed[i] = 1;
                count++;
                if (count >= n) return true;
            }
        }
    }
    return count >= n;
}

module.exports = { canPlaceFlowers };