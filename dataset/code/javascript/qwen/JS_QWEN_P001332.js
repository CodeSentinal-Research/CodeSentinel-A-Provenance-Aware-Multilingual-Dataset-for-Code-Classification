const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let minRem = Infinity;
    let res = [];
    function isValid(str) {
        let count = 0;
        for(let c of str) {
            if(c==='(') count++;
            else if(c===')') count--;
            if(count<0) return false;
        }
        return count===0;
    }
    function dfs(idx, curr, removed, leftRem, rightRem) {
        if(idx===s.length) {
            if(leftRem===0 && rightRem===0 && isValid(curr)) {
                if(removed<minRem) { minRem=removed; res=[curr]; }
                else if(removed===minRem) res.push(curr);
            }
            return;
        }
        let c = s[idx];
        if(c==='(') {
            if(leftRem>0) dfs(idx+1, curr, removed+1, leftRem-1, rightRem);
            dfs(idx+1, curr+'(', removed, leftRem, rightRem);
        } else if(c===')') {
            if(rightRem>0) dfs(idx+1, curr, removed+1, leftRem, rightRem-1);
            dfs(idx+1, curr+')', removed, leftRem, rightRem);
        } else {
            dfs(idx+1, curr+c, removed, leftRem, rightRem);
        }
    }
    let left=0, right=0;
    for(let c of s) {
        if(c==='(') left++;
        else if(c===')') {
            if(left>0) left--;
            else right++;
        }
    }
    dfs(0, "", 0, left, right);
    console.log([...new Set(res)].sort().join("\n"));
    rl.close();
});
