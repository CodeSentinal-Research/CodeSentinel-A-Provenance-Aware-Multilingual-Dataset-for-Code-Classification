Here is the JavaScript solution for the problem:

function restoreIpAddresses(s) {
    const res = [];
    const path = [];
    backtrack(0, 0, s, path, res);
    return res;
}

function backtrack(start, count, str, path, res) {
    if (count > 4) {
        return;
    }
    if (start === str.length && count === 4) {
        res.push(path.slice(0).join('.'));
        return;
    }

    for (let end = start + 1; end < str.length; end++) {
        const curr = str.slice(start, end + 1);
        if (curr.length > 1 && curr[0] == '0' || curr.length > 3 || parseInt(curr) > 255) {
            continue;
        }
        if (count === 3) {
            path.push(curr);
            backtrack(end + 1, count, str, path, res);
            path.pop();
        } else {
            path.push(curr);
            backtrack(end + 1, count + 1, str, path, res);
            path.pop();
        }
    }
}
This JavaScript code uses backtracking to solve the problem. The backtrack function takes the start index, count of remaining parentheses, the string, the current path and the result list as parameters. For each index i, it checks if it is the first parenthesis, then it checks if the next parentheses is a number within the range [1, 255], and if the number of remaining parentheses is less than 4, then it backtracks to the previous state. Otherwise, it adds the current number to the path, and then recursively backtracks to the next state. If the count of remaining parentheses is 4, then it only adds the current number to the path. After each state, it pops the last added number from the path.