function countEvenDigits(n) {
    n = Math.abs(n);
    if (n === 0) return 1;
    let count = 0;
    while (n > 0) {
        if ((n % 10) % 2 === 0) count++;
        n = Math.floor(n / 10);
    }
    return count;
}

module.exports = { countEvenDigits };
