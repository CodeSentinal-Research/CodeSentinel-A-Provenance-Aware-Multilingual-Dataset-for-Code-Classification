function convert(s, numRows) {
    if (numRows === 1 || numRows >= s.length) return s;

    const rows = Array.from({ length: numRows }, () => "");
    let curRow = 0;
    let goingDown = false;

    for (const c of s) {
        rows[curRow] += c;
        if (curRow === 0 || curRow === numRows - 1) goingDown = !goingDown;
        curRow += goingDown ? 1 : -1;
    }

    return rows.join('');
}

module.exports = { convert };