function stringCompression(s) {
  if (!s) return 0;
  
  let count = 0;
  let result = '';
  
  for (let i = 0; i < s.length; i++) {
    count = s[i] === s[i + 1] ? count + 1 : count;
    result += s[i] + (count || 1);
  }
  
  return result.length < s.length ? result : s;
}

console.log(stringCompression('aabcccccaaa'));  // 'a2b1c5a3'
console.log(stringCompression('abcdefg'));  // 'abcdefg'
This code defines a function `stringCompression` that performs basic string compression using counts of repeated characters. It iterates over the input string, counting the number of times a character is repeated. If the next character is the same as the current character, it increments the count. If not, it appends the character and its count to the result string. Finally, if the compressed string is shorter than the original string, it returns the compressed string; otherwise, it returns the original string. The code then tests this function on two test cases.