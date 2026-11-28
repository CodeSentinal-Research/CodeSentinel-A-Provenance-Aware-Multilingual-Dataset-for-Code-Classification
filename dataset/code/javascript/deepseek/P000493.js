function removeKdigits(num, k) {
    if(k >= num.length) return "0";
    
    let stack = [];
    for(let i = 0; i < num.length; i++) {
        while(stack.length && num[i] < stack[stack.length - 1] && k) {
            stack.pop();
            k--;
        }
        stack.push(num[i]);
    }
    
    while(k) {
        stack.pop();
        k--;
    }
    
    let res = stack.reduce((prev, curr) => prev + curr, '');
    return res.startsWith('0') ? res.slice(1) : res;
}