// Helper function to evaluate mindaystobuyfood for problem constraints.
function minDaysToBuyFood(s, n, m) {
    const totalFood = s * m;
    if ((n - m) * 6 < m && s > 6) return -1;
    if (m > n) return -1;
    return Math.floor((totalFood + n - 1) / n);
}

module.exports = { minDaysToBuyFood };