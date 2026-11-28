Sure, here is the JavaScript code for the problem.

function solve() {
    var fs = require('fs');
    process.stdin.resume();
    process.stdin.setEncoding('ascii');
    var input = '';
    process.stdin.on('data', function(data) {
        input += data;
    });
    process.stdin.on('end', function() {
        input = input.trim().split('\n').map(function(text) {
            return text.match(/[^\s]+/g);
        });
        var N = parseInt(input[0]);
        var tree = JSON.parse(input[1]);
        console.log(findMinHeightTrees(N, tree));
    });
}

function findMinHeightTrees(N, edges) {
    if (N === 1) return [0];
    var depths = new Array(N).fill(0), graph = new Array(N).fill().map((_, i) => []);
    for (var [u, v] of edges) {
        graph[u].push(v);
        graph[v].push(u);
        depths[u]++;
        depths[v]++;
    }
    var queue = [];
    for (var i = 0; i < N; i++) {
        if (depths[i] === 1) queue.push(i);
    }
    while (N > 2) {
        N -= queue.length;
        var newQueue = [];
        for (var i of queue) {
            for (var j of graph[i]) {
                if (--depths[j] === 1) newQueue.push(j);
            }
        }
        queue = newQueue;
    }
    return queue;
}

solve();
This program uses the Breadth-First Search (BFS) algorithm to find the root vertices of the minimum height trees in the given undirected tree. The BFS algorithm is used because it explores all the vertices at the current depth before moving to the next level. The time complexity of this program is O(N).