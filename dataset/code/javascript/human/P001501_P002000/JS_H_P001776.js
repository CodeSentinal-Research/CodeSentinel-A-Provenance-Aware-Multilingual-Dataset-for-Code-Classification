export default {
  id: 'palindromic-substrings',
  title: 'Palindromic Substrings',
  leetcode: { num: 647, slug: 'palindromic-substrings', difficulty: 'Medium', premium: false },
  pattern: 'Expand Around Center',
  summary:
    'Count how many substrings of a string are palindromes. Single characters ' +
    'count, and the same text at different positions counts separately. Expand ' +
    'outward from every possible center to find them all in O(n²) time.',
  intuition: [
    { heading: 'Brute force', body:
      'Enumerate all `n·(n+1)/2` substrings, and for each one check whether it ' +
      'reads the same forwards and backwards. Checking a substring is O(n), so the ' +
      'whole thing is **O(n³)** — far more work than needed.' },
    { heading: 'Key insight', body:
      'Every palindrome has a **center** it is symmetric about. There are only ' +
      '`2n−1` centers (n single chars for odd-length palindromes, n−1 gaps for ' +
      'even-length ones). This is the **exact same machinery** as Longest ' +
      'Palindromic Substring — the only change is what we do with each hit.' },
    { heading: 'Optimal approach', body:
      'From each center, push two pointers `l` and `r` outward. Every time ' +
      '`s[l] === s[r]` you have found one more palindrome, so do `count++` — each ' +
      'expansion level is a **distinct** substring. The moment they differ (or run ' +
      'off the ends) that center is exhausted. Total work is **O(n²)**.' },
  ],
  code: `function countSubstrings(s) {
  let count = 0;
  for (let c = 0; c < s.length; c++) {
    for (const off of [0, 1]) {
      let l = c, r = c + off;
      while (l >= 0 && r < s.length && s[l] === s[r]) {
        count++;
        l--;
        r++;
      }
    }
  }
  return count;
}`,
  complexity: {
    time: 'O(n²)', timeWhy: '2n−1 centers, each expanding at most n steps outward',
    space: 'O(1)', spaceWhy: 'only the counter and two pointers — no extra structures',
  },
  defaultInput: { s: 'aaa' },
  inputSpec: {
    s: { type: 'string', label: 'String', maxLen: 10 },
  },
  visual: 'array+vars',
  tests: [
    { input: { s: 'abc' }, expected: 3 },
    { input: { s: 'aaa' }, expected: 6 },
    { input: { s: 'a' }, expected: 1 },
  ],
  run(input, t) {
    const { s } = input;
    const chars = [...s];
    // Renderer: char row with l/r pointers; window [l,r] is the live palindrome,
    // status marks 'good' (confirmed match) or 'bad' (the pair that mismatched).
    const view = (l, r, count, status = {}) => {
      const inBounds = l >= 0 && r < chars.length;
      const row = {
        label: 's',
        values: chars,
        pointers: { l, r },
        status,
      };
      if (inBounds && l <= r) row.window = [l, r];
      return {
        array: { rows: [row] },
        vars: { entries: [
          ['count', count],
          ['l', l],
          ['r', r],
        ] },
      };
    };

    let count = 0;
    for (let c = 0; c < chars.length; c++) {
      for (const off of [0, 1]) {
        let l = c, r = c + off;
        const kind = off === 0 ? 'odd' : 'even';
        if (off === 1 && r >= chars.length) {
          // No even center past the last char; skip silently (matches code's while guard).
          continue;
        }
        t.step({
          line: 5,
          caption: `${kind} center at index ${c}${off ? `–${r}` : ''}: start l=${l}, r=${r} and push outward`,
          state: view(l, r, count),
        });
        while (l >= 0 && r < chars.length && chars[l] === chars[r]) {
          count++;
          const matched = `"${chars.slice(l, r + 1).join('')}"`;
          const goodStatus = {};
          for (let i = l; i <= r; i++) goodStatus[i] = 'good';
          t.step({
            line: 7,
            caption: `s[${l}]='${chars[l]}' === s[${r}]='${chars[r]}' → ${matched} is a palindrome, count = ${count}`,
            state: view(l, r, count, goodStatus),
            quiz: (count === 2) ? {
              question: `We already counted the inner "${chars[l + 1] ?? chars[l]}". Why does this wider match add to count again?`,
              options: [
                'Each expansion level is a different substring, so it counts separately',
                'We are re-counting the same substring by mistake',
                'Only the longest palindrome from a center counts',
              ],
              answer: 0,
              why: 'count++ fires on every successful expansion because each level spans a new range of indices.',
            } : undefined,
          });
          l--;
          r++;
        }
        // Why this center stopped: report the mismatch or the boundary.
        if (l >= 0 && r < chars.length) {
          t.step({
            line: 6,
            caption: `s[${l}]='${chars[l]}' ≠ s[${r}]='${chars[r]}' → this ${kind} center is done`,
            state: view(l, r, count, { [l]: 'bad', [r]: 'bad' }),
            quiz: (c === 1 && off === 1) ? {
              question: 'Why stop expanding the moment the two characters differ?',
              options: [
                'A palindrome must be symmetric; once a pair breaks, no wider span can be one',
                'We have already found enough palindromes',
                'The string has run out of characters',
              ],
              answer: 0,
              why: 'Widening only adds outer characters, so a mismatch at l,r dooms every larger span.',
            } : undefined,
          });
        } else {
          t.step({
            line: 6,
            caption: `pointers ran off the ends (l=${l}, r=${r}) → this ${kind} center is fully expanded`,
            state: view(l, r, count),
          });
        }
      }
    }
    t.step({
      line: 13,
      caption: `every center exhausted → ${count} palindromic substrings in total`,
      state: view(-1, chars.length, count),
    });
    return count;
  },
};
