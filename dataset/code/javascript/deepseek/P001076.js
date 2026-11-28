Here is the JavaScript code for the Floyd-Warshall algorithm:

function shortestPath(N, matrix) {
    var dp = new Array(N + 1);
    for (var i = 0; i <= N; i++)
        dp[i] = new Array(N + 1).fill(-1);

    for (var i = 1; i <= N; i++) {
        for (var j = 1; j <= N; j++) {
            if (i == j)
                dp[i][j] = 0;
            else if (matrix[i][j] == -1)
                dp[i][j] = Infinity;
            else dp[i][j] = matrix[i][j];
        }
    }

    for (var k = 1; k <= N; k++) {
        for (var i = 1; i <= N; i++) {
            for (var j = 1; j <= N; j++) {
                dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    for (var i = 1; i <= N; i++) {
        for (var j = 1; j <= N; j++) {
            console.log(dp[i][j] == Infinity ? 'INF' : dp[i][j], ' ');
        }
        console.log();
    }
}

In this code, we first initialize a 2D array `dp` with Infinity for all pairs of nodes. Then, for every edge, we update `dp[i][j]` to be the shorter distance between node `i` and `j`.

After updating `dp`, we then update `dp[i][j]` to be the shorter distance between all pairs of nodes.

Finally, we print the shortest distances between all pairs of nodes.

This code assumes that the input is a 2D array where `matrix[i][j]` is the weight of the edge from node `i` to `j`, or `-1` if there is no edge.