// Helper function to evaluate isvalidsudoku for problem constraints.
function isValidSudoku(board) {
    const seen = new Set();
    for (let i = 0; i < 9; i++) {
        for (let j = 0; j < 9; j++) {
            const c = board[i][j];
            if (c !== '.') {
                const rowKey = `${c} in row ${i}`;
                const colKey = `${c} in col ${j}`;
                const boxKey = `${c} in box ${Math.floor(i / 3)}-${Math.floor(j / 3)}`;
                if (seen.has(rowKey) || seen.has(colKey) || seen.has(boxKey)) {
                    return false;
                }
                seen.add(rowKey);
                seen.add(colKey);
                seen.add(boxKey);
            }
        }
    }
    return true;
}

module.exports = { isValidSudoku };