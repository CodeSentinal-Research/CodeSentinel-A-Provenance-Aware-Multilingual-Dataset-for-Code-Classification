process.stdin.resume();
process.stdin.on('data', function(data) {
    var N = parseInt(data.toString().trim());
    var costs = [];
    for (var i = 0; i < N; i++) {
        var cost = [];
        cost[0] = parseInt(process.stdin.readline().toString().trim());
        cost[1] = parseInt(process.stdin.readline().toString().trim());
        cost[2] = parseInt(process.stdin.readline().toString().trim());
        costs.push(cost);
    }
    console.log(minCost(costs));
});

function minCost(costs) {
    var dp = [];
    dp[0] = costs[0];
    dp[1] = Math.min(costs[0][0], costs[0][1]);
    dp[2] = Math.min(dp[1], costs[0][2]);
    for (var i = 1; i < costs.length; i++) {
        dp[i] = Math.min(dp[i - 1], dp[i - 2]) + costs[i];
    }
    return Math.min(dp[dp.length - 1], dp[dp.length - 2]);
}
This code reads the number of houses and the costs for painting each house and for each house it calculates the minimum cost to paint the house. The dp array stores the minimum cost for each house to be painted. The time complexity is O(n), where n is the number of houses.