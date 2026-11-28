// Helper function to evaluate getrow for problem constraints.
function getRow(rowIndex) {
    const row = [1];
    for (let i = 0; i < rowIndex; i++) {
        for (let j = row.length - 1; j > 0; j--) {
            row[j] = row[j] + row[j - 1];
        }
        row.push(1);
    }
    return row;
}

module.exports = { getRow };