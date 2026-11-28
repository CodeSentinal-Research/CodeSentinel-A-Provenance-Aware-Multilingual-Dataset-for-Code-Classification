Here is the JavaScript code to solve the problem:

function isValid(s) {
    var stack = [];
    for(var i = 0; i < s.length; i++) {
        if(s[i] === '(' || s[i] === '{' || s[i] === '[') {
            stack.push(s[i]);
        } else if(s[i] === ')' || s[i] === '}' || s[i] === ']') {
            if(stack.length === 0) {
                return false;
            }
            if(s[i] === ')' && stack[stack.length - 1] !== '(') {
                return false;
            }
            if(s[i] === '}' && stack[stack.length - 1] !== '{') {
                return false;
           
            }
            if(s[i] === ']' && stack[stack.length - 1] !== '[') {
                return false;
            }
            stack.pop();
        }
    }
    return (stack.length === 0)
}

In this code, we use a stack to handle the string. We loop through each character in the string. If the character is an opening bracket, we push it to the stack. If it is a closing bracket, we first check if the stack is empty. If it is, then we return false. Then we check if the closing bracket matches the last bracket in the stack. If they don't match, we return false. If they do match, we pop the last bracket from the stack. If the end of the string is reached without finding a mismatch, we check if the stack is empty. If it is not, we return false. If the stack is empty, we return true.