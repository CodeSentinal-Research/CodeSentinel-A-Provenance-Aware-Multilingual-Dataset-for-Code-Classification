function printFloydTriangle(n) {
    const res = [];
    let num = 1;
    for (let i = 1; i <= n; i++) {
        const row = [];
        for (let j = 0; j < i; j++) {
            row.push(num++);
        }
        res.push(row);
    }
    return res;
}

module.exports = { printFloydTriangle };
