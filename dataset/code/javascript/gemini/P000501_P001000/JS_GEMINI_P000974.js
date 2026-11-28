// Helper function to evaluate euclideandistance for problem constraints.
function euclideanDistance(x1, y1, x2, y2) {
    return Math.hypot(x2 - x1, y2 - y1);
}

module.exports = { euclideanDistance };