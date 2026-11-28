function decodeString(s) {
  let stack = [];
  for (let i = 0; i < s.length; i++) {
    if (s[i] === ']') {
      let repeat = '';
      while (stack[stack.length - 1] !== '[') {
        repeat = stack.pop() + repeat;
      }
      stack.pop();
      let k = '';
      while (stack[stack.length - 1] !== '[') {
        k += stack.pop();
      }
      stack.pop();
      let repeated = repeat * k;
      stack.push(repeated);
    } else {
      stack.push(s[i]);
    }
  }
  return stack.join('');
}
In this JavaScript code, we use a stack to decode the encoded string. Each time we encounter ']' in the string, we pop all the characters until the previous '[' from the stack and repeat the character. The repetition count and repeated string are then pushed back to the stack. At the end, we join the stack to get the decoded string.