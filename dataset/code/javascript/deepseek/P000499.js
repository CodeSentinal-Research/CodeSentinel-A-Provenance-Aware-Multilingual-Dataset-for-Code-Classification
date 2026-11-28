Here's the JavaScript code:

function makeTheStringGreat(s) {
  if (s.length < 2) {
    return s;
  }

  let result = s[0];
  for (let i = 1; i < s.length; i++) {
    if (s[i] !== s[i - 1]) {
      result += s[i];
    }
  }

  return result;
}

console.log(makeTheStringGreat('aaabbbcc'));

This function takes a string as input, checks if its length is less than 2. If it is, it returns the string as it's already a good string.

If the string's length is greater than or equal to 2, it creates a new string, starting with the first character of the input string.

Then, it iterates through the rest of the string, checking if the current character is different from the previous one. If it is, it adds the current character to the result string.

Finally, it returns the result string, which is the resulting good string.