// Helper function to evaluate printlevels for problem constraints.
function printLevels(arr) {
    const n = arr.length;
    let level = 0, start = 0;
    const res = [];
    while (start < n) {
        const count = 1 << level;
        const end = Math.min(n, start + count);
        res.push(arr.slice(start, end).join(' '));
        start = end;
        level++;
    }
    return res.join('\n');
}

module.exports = { printLevels };