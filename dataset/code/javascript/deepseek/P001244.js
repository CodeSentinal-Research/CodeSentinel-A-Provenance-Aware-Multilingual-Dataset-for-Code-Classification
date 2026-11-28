Here is a simple JavaScript code to rearrange a string without repeating characters. This code uses a stack data structure to solve the problem.

function rearrangeString(str) {
    let charFreq = {};
    let stack = [];
    let result = '';

    // Calculate the frequency of each character
    for (let char of str) {
        charFreq[char] = (charFreq[char] || 0) + 1;
    }

    // Add all characters to the stack
    for (let char in charFreq) {
        stack.push(char);
    }

    // Keep removing two characters from the stack until the stack is empty
    while (stack.length > 0) {
        if (charFreq[stack[0]] > 0) {
            result += stack[0];
            charFreq[stack[0]]--;
        } else {
            stack.shift();
       
            if (stack.length > 0) {
                result += stack[0];
                charFreq[stack[0]]--;
            }
        }
    }

    // Check if there is any character with count more than 1
    for (let char in charFreq) {
        if (charFreq[char] > 0) {
            return 'IMPOSSIBLE';
        }
    }

    return result;
}

In this code, we first calculate the frequency of each character in the string. Then, we add all characters to the stack. We keep removing two characters from the stack until the stack is empty. If the character in the stack is not in the string, we move it to the end. If it is in the string, we decrement its frequency and add it to the result. If there is any character with count more than 0, it means we cannot rearrange the string, so we return 'IMPOSSIBLE'.