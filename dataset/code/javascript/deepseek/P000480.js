function removeDuplicates(s) {
    let stack = [];
    for(let ch of s) {
        if(stack.length && stack[stack.length-1] == ch) {
            stack.pop();
        } else {
            stack.push(ch);
        }
    }
    return stack.join('');
}
This JavaScript function takes a string `s` as input. It creates a stack to store characters. It iterates through each character in the string. If the stack is not empty and the top of the stack is the current character, it removes the top of the stack (which is the duplicate of the current character). Otherwise, it pushes the current character onto the stack. Finally, it returns the string representation of the stack.