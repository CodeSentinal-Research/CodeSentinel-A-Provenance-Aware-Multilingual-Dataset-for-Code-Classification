function longestValidParentheses(s) {
    let maxLen = 0;
    let stack = [-1]; // initialize the stack with -1 as the base

    for(let i = 0; i < s.length; i++){
        if(s[i] == '('){
            stack.push(i); // push the index of '(' into the stack
        } else {
            stack.pop(); // pop the top of the stack
            if(stack.length == 0){
                // if the stack is empty, push the index + 1 to the stack
                stack.push(i + 1); 
            } else {
                // if the stack is not empty, calculate the longest valid parentheses length
                maxLen = Math.max(maxLen, i - stack[stack.length - 1]);
            }
        }
    }
    return maxLen;
}