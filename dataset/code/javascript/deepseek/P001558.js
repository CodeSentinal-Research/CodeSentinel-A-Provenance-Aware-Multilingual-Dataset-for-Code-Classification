Here is the JavaScript code for the problem:

let lines = process.stdin.read()
  .toString()
  .trim()
  .split('\n');

let [s, k] = lines;
s = s.split('');
k = parseInt(k);

let l = 0;
let maxLen = 0;
let charCounts = new Map();

for (let r = 0; r < s.length; r++) {
  charCounts.set(s[r], (charCounts.get(s[r]) || 0) + 1);

  while (charCounts.size > k) {
    charCounts.set(s[l], (charCounts.get(s[l]) || 1) - 1);
    if (charCounts.get(s[l]) === 0) {
      charCounts.delete(s[l]);
    }
    l++;
  }

  maxLen = Math.max(maxLen, r - l + 1);
}

console.log(maxLen);

This code reads the input line by line, and it maintains a window of the longest substring with at most `k` distinct characters. It uses a Map to keep track of the count of each character in the window. When the size of the Map exceeds `k`, it moves the left pointer `l` to the right, and decrease the count of the leftmost character in the window, until the size of the Map becomes less than or equal to `k`. The maximum length of the window is updated whenever it is found.