Sure, here is a simple JavaScript solution for the given problem. This solution uses a stack to store the unique characters and a hash map to record their count. 

function removeDuplicateLetters(s) {
    let stack = [];
    let count = new Array(26).fill(0);

    for(let c of s) {
        count[c.charCode() - 'a'.charCode()]++;
    }

    for(let c of s) {
        if(count[c.charCode() - 'a'.charCode()] > 0) {
            count[c.charCode() - 'a'.charCode()]--;
            continue;
        }

        while(stack.length > 0 && c < stack[stack.length - 1] && count[stack[stack.length - 1].charCode() - 'a'.charCode()] > 0) {
            let popChar = stack.pop();
            count[popChar.charCode() - 'a'.charCode()]++;
        }

        stack.push(c);
    }

    return stack.join('');
}

console.log(removeDuplicateLetters('bcabc')); // Output: abc

This solution iterates through the string only once and constructs a stack that stores the unique characters from left to right. The stack is used to ensure that the next character to be added to the final string is always on the right side of the current character and can only be added after it has been added to the stack before. The stack is updated in a way that the last character added to the stack will always be in the rightmost position, thus the smallest lexicographically.