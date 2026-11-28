Here is a JavaScript solution for the Maximal Square problem:

process.stdin.on('data', (data) => {
    const [R, C] = data.toString().split(' ').map(Number)
    const matrix = []

    for (let i = 0; i < R; i++) {
        matrix.push(data.toString().split(' ').map(Number))
        data = process.stdin.read()
    }

    const dp = Array.from(matrix, () => Array(C).fill(0))

    let maxSize = 0

    for (let i = 0; i < R; i++) {
        for (let j = 0; j < C; j++) {
            if (matrix[i][j] === 1) {
                if (i > 0 && j > 0) {
                    dp[i][j] = Math.min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1
                } else {
                    dp[i][j] = 1
                }
                maxSize = Math.max(maxSize, dp[i][j])
            }
        }
    }

    console.log(maxSize * maxSize)
})

This code uses a dynamic programming approach to solve the Maximal Square problem. The DP table is initialized with 0s. For each cell in the matrix, if it is a 1, then it checks the minimum of its top, left, and top-left neighbors and adds 1 to it. The maximum size of the square is updated every time a larger square is found. Finally, the area of the largest square is calculated and printed.

This code assumes that you're running it in a Node.js environment and that you're piping input into it. If you're running this in a different environment or if you're not using Node.js, you'll need to adjust the code accordingly.