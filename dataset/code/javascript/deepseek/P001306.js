process.stdin.resume();
process.stdin.on('data', function(data) {
    var N = parseInt(data.toString().trim());
    var sizes = [];
    process.stdin.on('data', function(data) {
        sizes.push(parseInt(data.toString().trim()));
        if(sizes.length == N) {
            console.log(minCost(sizes));
            process.stdin.pause();
        }
    });
});

function minCost(sizes) {
    sizes.sort(function(a, b) {
        return a - b;
    });
    var cost = 0;
    for(var i = 0; i < sizes.length; i++) {
        cost += (i+1) * sizes[i];
    }
    return cost;
}

This JavaScript code reads the number of files and their sizes from the standard input. It then sorts the sizes array and calculates the minimum total merging cost. The cost is calculated as the sum of the merged file sizes, which is the same as the sum of the merge costs. The merge costs are calculated as the sum of the merged file sizes, which is the same as the sum of the merge costs.