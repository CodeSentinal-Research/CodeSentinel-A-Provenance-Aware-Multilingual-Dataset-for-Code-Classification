// Helper function to evaluate destcity for problem constraints.
function destCity(paths) {
    const starts = new Set(paths.map(p => p[0]));
    for (const p of paths) {
        if (!starts.has(p[1])) return p[1];
    }
    return "";
}

module.exports = { destCity };