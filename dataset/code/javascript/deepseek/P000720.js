Here is the JavaScript code for the problem:

function addOperators(num, target) {
    let res = [];
    backtrack(num, target, '', 0, 0, 0);
    return res;
};

function backtrack(num, target, curr, prev,乘积,指数) {
    if(curr.length === num.length * 2){
        if(target === 乘积){
            res.push(curr);
        }
        return;
    }
    
    for(let i = 0; i < num.length; i++){
        let next = num.slice(i === 0 ? 1 : 0, i + 1);
        let nextPrev = num.slice(0, i + 1);
        let nextProduct = i === 0 ? next : 乘积 * 10 + next;
        let nextExponent = i === 0 ? next : 10 * （exponent + next）+ next;
        
        if(i > 0){
            backtrack(num, target, curr + '*' + nextPrev, nextPrev, nextProduct, nextExponent);
        }else{
            backtrack(num, target, nextPrev + next, nextPrev, nextProduct, nextExponent);
            backtrack(num, target, curr + '/' + nextPrev, -nextPrev, 乘积 / nextProduct, nextExponent);
        }
        if(nextProduct <= target && nextExponent >= 1){
            backtrack(num, target, curr + '+' + nextPrev, nextPrev, nextProduct, nextExponent);
        }
    }
}

In this code, we use a depth-first search (DFS) strategy to explore all possible ways of inserting operators between the digits in the given number. 

The backtrack function takes in the current number, target value, the current expression to be added, the previous digit, the product of the previous digits, and the exponentiation of the previous digits. We iterate over the digits of the number. For each digit, we add it to the current expression if it's not the first digit. If it's the first digit, we add the operator and the previous digit to the current expression.

We also need to consider the constraints that all numbers and the result must be less than or equal to the target, and the result must be greater than or equal to 1. 

This DFS approach finds all the valid expressions in lexicographical order, so we return the result list in lexicographical order.