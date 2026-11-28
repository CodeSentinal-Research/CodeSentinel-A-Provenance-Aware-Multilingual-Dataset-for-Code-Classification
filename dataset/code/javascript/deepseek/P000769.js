Here is a JavaScript code that solves the problem using memoization:

let memo = new Map();

function isScramble(s1, s2) {
  // Base cases
  if (s1.length !== s2.length) return false;
  if (s1 === s2) return true;
  if (s1.length === 1) return s1 === s2;

  // Check if this combination is in the memo
  if (memo.has(s1 + ',' + s2)) return memo.get(s1 + ',' + s2);

  // Try to make s2 by swapping each character
  for (let i = 1; i < s1.length; i++) {
    if (
      (isScramble(s1.slice(0, i), s2.slice(0, i)) &&
      isScramble(s1.slice(i), s2.slice(i))
    ) {
      memo.set(s1 + ',' + s2, true);
      return true;
    }
    if (
      (isScramble(s1.slice(0, i), s2.slice(-i)) &&
      isScramble(s1.slice(i), s2.slice(0, -i))
    ) {
      memo.set(s1 + ',' + s2, true);
      return true;
    }
  }

  // If no swaps can work
  memo.set(s1 + ',' + s2, false);
  return false;
}

You can use this function like this:

console.log(isScramble("abc", "cab")); // true
console.log(isScramble("abc", "bac")); // false

The `isScramble` function uses memoization to avoid repeated calculations. The function first checks if the input strings are equal, if they are, it returns true. Then it checks if the input strings are all single characters, if they are, it returns whether they are equal. If they are not all single characters, it tries to make `s2` by swapping each character of `s1`. If it can make `s2` with a swap, it returns true. If it cannot make `s2`, it returns false. The results are stored in a `Map` and are reused if the same combination of `s1` and `s2` is calculated again.