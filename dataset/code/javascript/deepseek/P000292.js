Here is the JavaScript solution for the given problem.

function decodeString(s) {
    let stack = [];
    let i = 0;
    
    while(i < s.length) {
        if(s[i] === '[') {
            stack.push(i);
            i++;
        } else if(s[i] === ']') {
            let repeat = '';
            while(s[i-1] !== '[') {
                repeat = s[i-1] + repeat;
                i--;
            }
            i--;
            
            let repeatNum = parseInt(repeat);
            let substring = s.slice(stack.pop(), i);
            let decodedString = substring.repeat(repeatNum);
            
            s = s.slice(0, stack.pop()) + decodedString;
            i = stack.length > 0 ? stack[stack.length - 1] + decodedString.length : decodedString.length;
        } else {
            i++;
        }
    }
    
    return s;
}

This function uses a stack to track the position of the brackets in the encoded string. For each opening bracket, it pushes the position onto the stack, then increments the index. When a closing bracket is found, it pops the position from the stack, uses this as the start index for the substring, repeats the substring according to the number inside the brackets, then pushes the new string back onto the stack. After all brackets have been processed, it pops the last remaining string from the stack and returns it.