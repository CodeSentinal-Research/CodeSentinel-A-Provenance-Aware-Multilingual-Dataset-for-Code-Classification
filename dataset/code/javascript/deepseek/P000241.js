const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the number of rows: ', (numRows) => {
    let matrix = [];
    rl.setPrompt(`Enter matrix ${numRows} x ${numRows}:\n`);
    for(let i = 0; i < numRows; i++) {
        matrix.push(rl.question(''));
    }

    let saddlePoints = findSaddlePoints(matrix);
    console.log(saddlePoints.join(', '));

    rl.close();
});

function findSaddlePoints(matrix) {
    let saddlePoints = [];
    for(let i = 0; i < matrix.length; i++) {
        let row = matrix[i];
        for(let j = 0; j < row.length; j++) {
            let column = matrix.map(r => r[j]);
            if(isSaddlePoint(row, column)) {
                saddlePoints.push([i, j]);
            }
        }
    }
    return saddlePoints;
}

function isSaddlePoint(row, column) {
    let minInRow = Math.min(...row);
    let maxInColumn = Math.max(...column);
    let isSaddle = true;
    for(let i = 0; i < row.length; i++) {
        if(row[i] !== minInRow) {
            isSaddle = false;
            break;
        }
    }
    if(isSaddle) for(let i = 0; i < column.length; i++) {
        if(column[i] !== maxInColumn) {
            isSaddle = false;
            break;
        }
    }
    return isSaddle;
}