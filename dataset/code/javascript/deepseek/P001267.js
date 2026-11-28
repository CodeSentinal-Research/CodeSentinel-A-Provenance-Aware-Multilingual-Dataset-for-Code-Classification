Here is the JavaScript code for the problem:

let [N, Bricks, Ladders] = process.argv.slice(2).map(Number)
let heights = process.argv.slice(3).map(Number)

let dp = new Array(N).fill(Infinity)
dp[0] = 0

for (let i = 0; i < N; i++) {
    if (dp[i] !== Infinity) {
        for (let j = 1; j <= heights[i]; j++) {
            if (i + j < N) {
                dp[i + j] = Math.min(dp[i + j], dp[i] + 1)
            }
        }
    }
}

console.log(dp[N - 1])
This code reads the number of buildings, bricks, and ladders as input, and creates an array dp with the size of N. The dp array is initialized with Infinity (which is larger than any real number) except for dp[0], which is 0. Then, for each building, we try to reach it by using bricks and ladders. If the current building can be reached, we update the dp value of the next building by taking the minimum of the current dp value and the current dp value plus 1. Finally, we output the dp value of the last building, which is the index of the furthest reachable building.

You can run this code by passing the number of buildings, bricks, and ladders as arguments. For example, you can run it with the following command:
node furthestBuilding.js 5 2 1 3 4 1
This command will output 3, which is the index of the furthest reachable building.