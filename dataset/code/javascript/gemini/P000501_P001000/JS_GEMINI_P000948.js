// Helper function to evaluate chessboardgame for problem constraints.
function chessboardGame(x, y) {
    x = (x - 1) % 4;
    y = (y - 1) % 4;
    if ((x === 0 || x === 1) && (y === 0 || y === 1)) {
        return "Second";
    }
    return "First";
}

module.exports = { chessboardGame };