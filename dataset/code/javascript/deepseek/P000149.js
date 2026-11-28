let matrix = []

function processMatrix(rows, cols, data) {
    for (let i = 0; i < rows; i++) {
        matrix.push(data.splice(0, cols).map(Number))
    }
}

function findMaxOnesRow(rows, cols, data) {
    let maxOnes = 0
    let maxRow = -1

    processMatrix(rows, cols, data)

    matrix.forEach((row, index) => {
        const numOnes = row.reduce((acc, cur) => acc + cur, 0)
        if (numOnes > maxOnes) {
            maxOnes = numOnes
            maxRow = index
        }
    })

    return maxRow
}

// Test
console.log(findMaxOnesRow(3, 4, [1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1])) // Output: 2