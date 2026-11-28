Here is the JavaScript code for the problem:

process.stdin.resume();
process.stdin.on('data', function(data) {
    var n = parseInt(data);
    var tree = [];
    for(var i = 0; i < n; i++) {
        process.stdin.readLine();
        var treeLine = process.stdin.readLine().split(' ');
        tree.push(parseInt(treeLine[0]), treeLine[1]);
    }
    findModes(tree).forEach(console.log);
    process.stdin.pause();
});

function findModes(tree) {
    var counts = {}, modes = [], maxCount = 0, mode;
    tree.forEach(function(node) {
        counts[node] = (counts[node] || 0) + 1;
        if (counts[node] > maxCount) {
            maxCount = counts[node];
            modes = [node];
        } else if (counts[node] === maxCount) {
            modes.push(node);
        }
    });
    modes.sort(function(a, b) { return a - b; });
    return modes;
}
This script reads the input from standard input and then calls the `findModes` function with the input tree as an argument. The `findModes` function finds the modes of the binary tree and returns them in ascending order. The modes are then printed to standard output.

Please note that this code assumes that the input is a valid binary tree. It does not handle the case where the binary tree is not a complete binary tree. Also, it does not handle the case where there are multiple modes.