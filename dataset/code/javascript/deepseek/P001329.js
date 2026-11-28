Here's the JavaScript code for the problem:

const fs = require('fs');
process.stdin.resume();
process.stdin.setEncoding('ascii');

var input = "";
process.stdin.on('data', function(data){
    input += data;
});

process.stdin.on('end', function(){
    input = input.split('\n');
    var N = parseInt(input[0]);
    var nums = input[1].split(' ').map(Number);
    var result = permuteUnique(nums, N);
    fs.writeFileSync("output.txt", result.join("\n"));
});

function permuteUnique(nums, N) {
    nums.sort((a, b) => a - b);
    let result = [];
    let path = [];
    backtrack(nums, N, 0, path, result);
    return result;
}

function backtrack(nums, N, first, path, result) {
    if (path.length == N) {
        result.push(path.slice());
        return;
    }
    for (let i = first; i < nums.length; i++) {
        if (path.includes(nums[i])) {
            continue;
        }
        path.push(nums[i]);
        backtrack(nums, N, i + 1, path, result);
        path.pop();
    }
}
This JavaScript code takes an integer array as input and generates all unique permutations of the array. The `permuteUnique` function first sorts the array and then uses a backtracking algorithm to generate all permutations. The `backtrack` function is a helper function that recursively generates permutations. If a number is already included in the path, it skips to the next iteration.