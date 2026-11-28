Here is a JavaScript solution for the given problem:

function removeDuplicates(S, K) {
    let stack = [];
    for (let i = 0; i < S.length; i++) {
        if (stack.length === 0 || stack[stack.length - 1][0] !== S[i]) {
            stack.push([S[i], 1]);
        } else {
            stack[stack.length - 1][1]++;
            if (stack[stack.length - 1][1] === K) {
                stack.pop();
            }
        }
    }
    return stack.map(item => item.join('')).join('');
}

This function uses a stack to track the characters and their counts. The stack is initialized with the first character of the string and its count. For each character in the string, the function checks if the current character is the same as the top of the stack. If it is, the count is incremented and the function continues to the next character. If the characters are not the same, the character and its count are pushed into the stack. If the count reaches K, the top of the stack is popped out. After processing all characters, the function joins the stack back into a string and returns it.