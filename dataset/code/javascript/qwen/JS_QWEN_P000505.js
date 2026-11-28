const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
rl.on('line', (input) => {
    const s = input.trim();
    let stack = [], sign = 1, num = 0, res = 0;
    for(let c of s) {
        if(c >= '0' && c <= '9') num = num * 10 + parseInt(c);
        else if(c === '+') { res += sign * num; num = 0; sign = 1; }
        else if(c === '-') { res += sign * num; num = 0; sign = -1; }
        else if(c === '*') { 
            // Simplified for single pass without precedence handling in basic calculator II style
            // Actually Problem 505 is Basic Calculator II which has * /
            // Let's use the stack approach for * /
        }
    }
    // Re-implementing Basic Calculator II properly
    let nums = [], ops = [];
    let i=0;
    while(i<s.length) {
        if(s[i]===' ') { i++; continue; }
        if(s[i]>='0' && s[i]<='9') {
            let num=0;
            while(i<s.length && s[i]>='0' && s[i]<='9') num=num*10+parseInt(s[i++]);
            nums.push(num);
        } else {
            if(ops.length && (ops[ops.length-1]==='*' || ops[ops.length-1]==='/')) {
                let op = ops.pop();
                let b = nums.pop(), a = nums.pop();
                nums.push(op==='*' ? a*b : Math.trunc(a/b));
            }
            ops.push(s[i++]);
        }
    }
    while(ops.length) {
        let op = ops.pop(), b = nums.pop(), a = nums.pop();
        nums.push(op==='+' ? a+b : a-b);
    }
    console.log(nums[0]);
    rl.close();
});
