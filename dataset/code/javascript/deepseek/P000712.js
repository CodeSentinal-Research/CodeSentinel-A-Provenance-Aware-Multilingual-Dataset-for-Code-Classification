Here is a JavaScript solution that uses recursive backtracking algorithm to solve the problem:

function combinationSum(n, candidates, target) {
    let result = [];
    candidates.sort((a, b) => a - b);
    backtrack(n, candidates, target, 0, [], result);
    return result;
}

function backtrack(n, candidates, target, start, curr, result) {
    if (target < 0) {
        return;
    }
    if (target === 0) {
        result.push(Array.from(curr));
        return;
    }
    for (let i = start; i < candidates.length; i++) {
        curr.push(candidates[i]);
        backtrack(n, candidates, target - candidates[i], i, curr, result);
        curr.pop();
    }
}

This solution works by using a recursive function `backtrack` to explore all possible combinations of the given numbers that sum up to the target. The function `combinationSum` first sorts the `candidates` array, then calls `backtrack` to start the exploration.

In `backtrack`, it first checks if the target is negative or zero, if so it immediately returns to avoid unnecessary computations. If the target is zero, it adds the current combination to the result and returns.

Then it iterates through all the possible numbers starting from the `start` index, and for each number, it pushes it into the current combination `curr`, then recursively calls `backtrack` to explore the remaining numbers with the new target and current combination. After the recursive call, it removes the last added number from the current combination `curr`, and then returns to the previous state.

This solution guarantees the lexicographical order of the combinations.