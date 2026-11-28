Here is the JavaScript code to solve the problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('', (S) => {
  rl.question('', (T) => {
    if (isIsomorphic(S, T)) {
      console.log('YES');
    } else {
      console.log('NO');
    }
    rl.close();
  });
});

function isIsomorphic(S, T) {
  if (S.length !== T.length) {
    return false;
  }

  let charMap = new Map();
  let reversedCharMap = new Map();

  for (let i = 0; i < S.length; i++) {
    let charS = S[i], charT = T[i];

    if (charMap.has(charS)) {
      if (charMap.get(charS) !== charT) {
        return false;
      }
    } else {
      charMap.set(charS, charT);
    }

    if (reversedCharMap.has(charT)) {
      if (reversedCharMap.get(charT) !== charS) {
        return false;
      }
    } else {
      reversedCharMap.set(charT, charS);
    }
  }

  return true;
}
This code reads two strings from the standard input, checks if they are isomorphic, and prints the result to the standard output. The `isIsomorphic` function creates two maps to keep track of the character mappings. It iterates over the characters of the strings, checking if the current character is already in the map for the corresponding string. If the mapping is correct, it updates the map for the other string. If the mapping is not correct, it returns false.