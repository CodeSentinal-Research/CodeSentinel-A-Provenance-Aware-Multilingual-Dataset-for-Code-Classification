Here is the JavaScript code that can solve the problem:

function solveProblem() {
    var N = parseInt(readline());
    var keys = readline().split(' ').map(Number);
    var frequencies = readline().split(' ').map(Number);
    var minCost = Infinity;
    var minKeys = null;
    var dp = [];

    function buildTree(keys, freqs, left, right) {
        if (left > right) {
            return null;
        }

        var minIdx = left;
        for (var i = left; i <= right; i++) {
            if (dp[i] < dp[minIdx] && freqs[i] > 0) {
                minIdx = i;
            }
        }

        var root = keys[minIdx];
        dp[minIdx] += freqs[minIdx];
        freqs[minIdx] = 0;

        var leftFreq = freqs[left];
        var rightFreq = freqs[right];

        buildTree(keys, freqs, left, minIdx - 1);
        buildTree(keys, freqs, minIdx + 1, right);
    }

    function solve(keys, freqs, left, right) {
        if (left > right) {
            return;
        }

        var mid = Math.floor((left + right) / 2);
        if (Math.abs(mid - left) < Math.abs(mid - right) && Math.abs(mid - left) < minCost) {
            minCost = Math.abs(mid - left);
            minKeys = [keys[left], keys[mid], keys[right]];
        }

        solve(keys, freqs, left, mid - 1);
        solve(keys, freqs, mid + 1, right);
    }

    buildTree(keys, frequencies, 0, N - 1);
    solve(keys, frequencies, 0, N - 1);

    console.log(minCost);
    console.log(minKeys.join(' '));
}

function readline() {
    return process.stdin.readLine();
}

solveProblem();

This code first reads the input from the standard input, then calls the solve function to find the optimal keys for the minimum average search cost. The solve function uses binary search to find the minimum cost and buildTree function constructs the optimal binary search tree.

Please note that this code assumes that the input is a valid problem and does not handle errors or edge cases.