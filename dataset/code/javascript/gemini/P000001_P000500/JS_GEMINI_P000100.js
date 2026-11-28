function printPascalTriangle(n) {
    for (let i = 0; i < n; i++) {
        let row = [];
        let val = 1;
        for (let j = 0; j <= i; j++) {
            row.push(val);
            val = Math.floor(val * (i - j) / (j + 1));
        }
        console.log(row.join(" "));
    }
}

module.exports = { printPascalTriangle };