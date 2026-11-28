function convertDays(totalDays) {
    const years = Math.floor(totalDays / 365);
    const rem = totalDays % 365;
    const weeks = Math.floor(rem / 7);
    const days = rem % 7;
    return [years, weeks, days];
}

module.exports = { convertDays };
