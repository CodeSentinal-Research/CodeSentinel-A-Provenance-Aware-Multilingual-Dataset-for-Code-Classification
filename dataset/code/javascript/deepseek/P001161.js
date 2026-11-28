function isMatch(text, pattern) {
  if (pattern.length === 0) {
    return text.length === 0;
  }

  if ('*' === pattern[0]) {
    return isMatch(text, pattern.slice(1)) || isMatch(text.slice(1), pattern);
  }

  if ('?' === pattern[0]) {
    return isMatch(text.slice(1), pattern.slice(1));
  }

  if (text[0] !== pattern[0]) {
    return false;
  }

  return isMatch(text.slice(1), pattern.slice(1));
}

console.log(isMatch(readline().trim(), readline().trim()) === 'YES' ? 'YES' : 'NO');

This JavaScript code uses recursion and dynamic programming to solve the wildcard pattern matching problem. The isMatch function checks if the current characters in the text and the pattern match. If the characters don't match, it returns false. If the pattern is empty, it checks if the text is also empty. If either condition is true, it returns true.

In the main part of the code, we read the text and pattern from the standard input, call the isMatch function with these inputs, and print the result in the standard output.