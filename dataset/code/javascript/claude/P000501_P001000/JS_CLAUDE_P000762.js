function printPattern(n) {
    const lines = [];
    for (let i = 1; i <= n; i++) {
        lines.push('* '.repeat(i).trim());
    }
    return lines;
}

module.exports = { printPattern };
