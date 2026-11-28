Here is the JavaScript code for your problem:

function combinationSum2(candidates, target) {
    candidates.sort((a, b) => a - b);
    let result = [];
    combinationSum2Helper(candidates, target, 0, [], result);
    return result;
}

function combinationSum2Helper(candidates, target, index, current, result) {
    if (target < 0) {
        return;
    }
    if (target === 0) {
        result.push(Array.from(current));
        return;
    }
    for (let i = index; i < candidates.length; i++) {
        if (i > index && candidates[i] === candidates[i - 1]) continue; // skip duplicates
        current.push(candidates[i]);
        combinationSum2Helper(candidates, target - candidates[i], i + 1, current, result);
        current.pop();
    }
}

This code uses the backtracking approach to find all combinations of the given numbers that sum up to the target. The function `combinationSum2` is the main function where we call `combinationSum2Helper` with the input parameters.

`combinationSum2Helper` is a helper function that recursively tries to find all combinations for the given target. It uses a stack to keep track of the current combination and recursively tries to find all combinations for the remaining part of the target.

The function `combinationSum2` sorts the candidates array and then calls `combinationSum2Helper` with the appropriate parameters.