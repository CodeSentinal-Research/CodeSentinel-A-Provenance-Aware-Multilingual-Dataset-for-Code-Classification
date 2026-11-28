function minAppend(s, t) {
  let appendCount = 0;
  let j = 0;

  for (let i = 0; i < s.length; i++) {
    if (s[i] == t[j]) {
      j++;
      if (j == t.length) {
        return appendCount;
      }
    } else {
      appendCount++;
    }
  }
}

//Example usage:
console.log(minAppend('abc', 'aab')); // Output: 2