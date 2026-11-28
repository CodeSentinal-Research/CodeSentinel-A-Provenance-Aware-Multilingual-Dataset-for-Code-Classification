function combinationSum(arr, target) {
    let result = [];
    let currentSum = 0;
    backtrack(arr, target, result, currentSum, []);
    return result;
}

function backtrack(arr, target, result, currentSum, currentCombination) {
    if (currentSum > target) {
        return;
    }
    if (currentSum === target) {
        result.push(currentCombination.slice());
        return;
    }
    for (let i = 0; i < arr.length; i++) {
        currentSum += arr[i];
        currentCombination.push(arr[i]);
        backtrack(arr, target, result, currentSum, currentCombination);
        currentSum -= arr[i];
        currentCombination.pop();
    }
}

let input1 = [2, 3, 6, 7];
let input2 = 7;
console.log(combinationSum(input1, input2));