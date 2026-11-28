// Helper function to evaluate tictactoe for problem constraints.
function tictactoe(moves) {
    const rows = [0, 0, 0], cols = [0, 0, 0];
    let diag = 0, antiDiag = 0;

    for (let i = 0; i < moves.length; i++) {
        const [r, c] = moves[i];
        const val = (i % 2 === 0) ? 1 : -1;

        rows[r] += val;
        cols[c] += val;
        if (r === c) diag += val;
        if (r + c === 2) antiDiag += val;

        if (rows[r] === 3 || cols[c] === 3 || diag === 3 || antiDiag === 3) return "A";
        if (rows[r] === -3 || cols[c] === -3 || diag === -3 || antiDiag === -3) return "B";
    }
    return moves.length === 9 ? "Draw" : "Pending";
}

module.exports = { tictactoe };