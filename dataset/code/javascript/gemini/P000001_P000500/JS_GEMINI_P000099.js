function printFloydTriangle(rows) {
    let num = 1;
    for (let i = 1; i <= rows; i++) {
        let row = [];
        for (let j = 1; j <= i; j++) {
            row.push(num++);
        }
        console.log(row.join(" "));
    }
}

module.exports = { printFloydTriangle };