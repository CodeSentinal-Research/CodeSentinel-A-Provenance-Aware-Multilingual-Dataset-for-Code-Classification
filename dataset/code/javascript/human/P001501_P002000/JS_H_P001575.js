const slidingWindowVariable = {
  slug: 'sliding-window-variable',
  eyebrow: 'Phase 2 — Sliding Window & Prefix Techniques',
  title: 'Sliding Window — Variable Size (Expand→Shrink)',
  lede: 'The variable-size variation lets the window grow and shrink based on a condition. The right pointer always advances; the left pointer only advances when the window becomes invalid. You are optimizing the window size itself.',
  overview: [
    { label: 'Time Complexity', value: 'O(N) amortized' },
    { label: 'Space Complexity', value: 'O(1) or O(distinct)' },
    { label: 'Key Pattern', value: 'Expand right, shrink left' },
  ],
  sections: [
    {
      num: '01',
      title: 'What is it?',
      blocks: [
        {
          type: 'p',
          text: 'Unlike the fixed-size variation, the variable-size window has no preset width. `right` advances every iteration. `left` only advances when the current window violates a constraint. The result you\'re optimizing is the window **size** itself (longest or shortest valid window).',
        },
      ],
    },
    {
      num: '03',
      title: 'When should I think about using it?',
      blocks: [
        {
          type: 'ul',
          items: [
            '"smallest/shortest subarray with sum ≥ target"',
            '"longest substring without repeating characters"',
            '"longest subarray with at most k distinct elements"',
            'Any problem where the window size is what you are optimizing, not a given constant.',
          ],
        },
      ],
    },
    {
      num: '04',
      title: 'How does it work?',
      blocks: [
        {
          type: 'ol',
          items: [
            'Initialize `left = 0`, `aggregate = initial`, `best = initial`.',
            'Advance `right` and fold `nums[right]` into the aggregate.',
            'Check validity. While the window is **invalid**, advance `left` and remove `nums[left]` from the aggregate.',
            'Update the best answer for the current valid window `[left, right]`.',
          ],
        },
        {
          type: 'callout',
          variant: 'rose',
          title: '⚠️ Critical: while, not if',
          text: 'The shrink step must be a **while loop**, not an `if`. An `if` only shrinks by one element per outer iteration, leaving the window invalid or missing the truly minimal window. This is the #1 bug on this variation.',
        },
      ],
    },
    {
      num: '05',
      title: 'Dry Run',
      titleSuffix: 'Minimum Size Subarray Sum (nums = [2, 3, 1, 2, 4, 3], target = 7)',
      blocks: [
        {
          type: 'table',
          headers: ['right', 'nums[right]', 'sum', 'sum≥7?', 'shrink actions', 'minLen'],
          rows: [
            ['0', '2', '2', 'no', '—', '∞'],
            ['1', '3', '5', 'no', '—', '∞'],
            ['2', '1', '6', 'no', '—', '∞'],
            ['3', '2', '8', 'yes', 'len4 → minLen=4; shrink: sum−=2→6, left=1 (6<7, stop)', '4'],
            ['4', '4', '10', 'yes', 'shrink: sum−=3→7 → len3 → minLen=3; sum−=1→6, left=3 (stop)', '3'],
            ['5', '3', '9', 'yes', 'shrink: sum−=2→7 → len2 → minLen=2; sum−=4→3, left=5 (stop)', '2'],
          ],
        },
        {
          type: 'p',
          text: 'Answer: **2** (window [4, 3]). The shrink step is a `while` loop nested inside the `right` loop — but `left` never moves backward across the whole run, so total left-movements are bounded by n, keeping this O(n) overall.',
        },
      ],
    },
    {
      num: '07',
      title: 'Time Complexity',
      blocks: [
        {
          type: 'ul',
          items: [
            '**O(n) amortized** — even though it looks like a nested loop, the right pointer advances at most n times and the left pointer advances at most n times **total across the whole run** (never backward). Total operations ≤ 2n.',
          ],
        },
      ],
    },
    {
      num: '08',
      title: 'Space Complexity',
      blocks: [
        {
          type: 'ul',
          items: [
            '**O(1)** for a numeric aggregate (sum/count).',
            '**O(distinct elements)** if the window carries a frequency map (e.g., "at most k distinct characters").',
          ],
        },
      ],
    },
    {
      num: '10',
      title: 'The Catch',
      titleSuffix: '⭐ What to watch out for',
      blocks: [
        {
          type: 'ul',
          items: [
            '**`if` instead of `while` for shrinking** — only shrinks by one element per outer iteration, leaves window invalid or misses minimal window.',
            '**Non-monotonic conditions** — the technique assumes that once a window becomes invalid, only shrinking (not some other operation) fixes it. Verify this before committing.',
            '**Forgetting to shrink entirely** — produces an oversized/invalid window; often a silent wrong answer, not a crash.',
            '**Using fixed-window logic** on a variable-size problem (or vice versa) — recognizing which variation applies is the core design decision.',
          ],
        },
      ],
    },
    {
      num: '17',
      title: 'Intuition',
      blocks: [
        {
          type: 'p',
          text: 'The key observation: "most of the window didn\'t change, only the edges did." Grow the window by advancing `right` until a constraint is violated, then shrink from the left to restore validity. Because neither pointer ever moves backward, the total work across the entire array is O(n), not O(n²) despite the nested appearance.',
        },
      ],
    },
    {
      num: '18',
      title: 'The Deeper Mental Model',
      blocks: [
        {
          type: 'p',
          text: 'Yes — **you\'ve noticed a very important sliding-window pattern**, and your intuition is mostly correct. There is just one wording/detail I want to sharpen.\n\nThe deeper idea is not really **"maximum → shrink when greater"** or **"minimum → shrink when smaller."**\n\nThe deeper idea is:\n> **First identify what makes the current window INVALID. Then decide whether to expand or shrink based on whether you are trying to find the longest or shortest VALID window.**'
        },
        {
          type: 'p',
          text: '### The core pattern\n\nThink of every sliding-window problem as:'
        },
        {
          type: 'ascii',
          content: `        EXPAND
           ↓
     Is window valid?
       ↙       ↘
     YES        NO
      ↓          ↓
   Can I        SHRINK
   improve      until valid
   answer?          ↓
      ↓          valid again
   record`
        },
        {
          type: 'p',
          text: 'But **maximum/longest** and **minimum/shortest** behave differently after you get a valid window.'
        },
        {
          type: 'collapse',
          title: '1. Maximum / Longest',
          defaultOpen: true,
          blocks: [
            {
              type: 'p',
              text: 'Suppose: > Find the **longest** subarray whose `sum <= k`.\n\nYour valid condition is: `sum <= k`\n\nTherefore:\n* `sum > k`  → INVALID ❌\n* `sum <= k` → VALID ✅\n\nSo when `sum > k`, you **must shrink**, because the current window cannot be used.\n\nOnce it becomes `sum <= k`, you have a valid window. Now what do you want?\n> **Make it as LONG as possible.**\n\nSo you don\'t immediately shrink a valid window. You **record it** and let `right` expand again.'
            },
            {
              type: 'ascii',
              content: `          expand
             ↓
        sum > k ?
        /       \\
      YES       NO
       ↓         ↓
    shrink    RECORD
       ↓         ↓
   valid again  expand`
            },
            {
              type: 'p',
              text: '**Helping Question #1**\n\nAsk yourself: > **"If my current window is already valid for a LONGEST problem, why would I remove something from it?"**\n\nUsually, you **wouldn\'t**, because removing elements makes the window smaller. That\'s the key intuition.'
            }
          ]
        },
        {
          type: 'collapse',
          title: '2. Minimum / Shortest',
          defaultOpen: true,
          blocks: [
            {
              type: 'p',
              text: 'Now suppose: > Find the **shortest** subarray whose `sum >= k`.\n\nValid condition: `sum >= k`\n\nTherefore:\n* `sum < k`  → INVALID ❌\n* `sum >= k` → VALID ✅\n\nWhen `sum < k`, you **must expand**, because you don\'t have a valid answer yet.\n\nEventually `sum >= k`. Now you have a valid window. But what are you trying to find?\n> **The SHORTEST valid window.**\n\nSo now you should do the opposite: **Keep shrinking while it remains valid.**'
            },
            {
              type: 'code',
              language: 'text',
              label: 'Example trace',
              code: {
                java: `[2, 3, 1, 2]
sum = 8 >= 7 ✅
length = 4

remove 2

[3, 1, 2]
sum = 6 < 7 ❌`,
                javascript: `[2, 3, 1, 2]
sum = 8 >= 7 ✅
length = 4

remove 2

[3, 1, 2]
sum = 6 < 7 ❌`
              }
            },
            {
              type: 'p',
              text: 'You just discovered that length `4` was valid, but you tried to make it smaller.'
            },
            {
              type: 'ascii',
              content: `expand until valid
        ↓
      VALID
        ↓
   record length
        ↓
     shrink
        ↓
 still valid?
   ↙       ↘
 YES       NO
 ↓          ↓
shrink     expand
again`
            },
            {
              type: 'p',
              text: '**Helping Question #2**\n\nAsk: > **"Once I have a valid window, can removing elements potentially give me a better answer?"**\n\n* **Longest?** Removing elements makes it shorter → usually **NO**\n* **Shortest?** Removing elements makes it shorter → **YES**\n\nThat\'s the fundamental distinction.'
            }
          ]
        },
        {
          type: 'p',
          text: '### 3. The really important insight\n\nHere\'s the mental framework I\'d recommend you memorize:\n\n**LONGEST / MAXIMUM**\n> **Find a valid window → try to make it bigger.**\n\nTherefore:\n* INVALID → shrink\n* VALID   → expand\n\n*(Example: Longest `sum <= k` → `sum > k` ? shrink ❌ : keep/expand ✅)*\n\n**SHORTEST / MINIMUM**\n> **Find a valid window → try to make it smaller.**\n\nTherefore:\n* INVALID → expand\n* VALID   → shrink\n\n*(Example: Shortest `sum >= k` → `sum < k` ? expand ❌ : shrink ✅)*'
        },
        {
          type: 'p',
          text: '### Helping Question #3 — the one to ask in every problem\n\nBefore writing code, ask:\n> **"What does a VALID window look like, and after I find one, do I want to make the window bigger or smaller?"**'
        },
        {
          type: 'table',
          headers: ['Problem', 'Valid condition', 'Goal', 'When invalid', 'When valid'],
          rows: [
            ['Longest subarray `sum <= k`', '`sum <= k`', 'Bigger', 'Shrink', 'Expand/record'],
            ['Shortest subarray `sum >= k`', '`sum >= k`', 'Smaller', 'Expand', 'Shrink/record'],
            ['Longest substring ≤ 2 distinct', '`map.size <= 2`', 'Bigger', 'Shrink', 'Expand/record'],
            ['Shortest substring with condition', 'condition satisfied', 'Smaller', 'Expand', 'Shrink/record']
          ]
        },
        {
          type: 'callout',
          variant: 'rose',
          title: 'One BIG caveat: Monotonicity',
          text: 'This reasoning works when the window has the required **monotonic behavior**, such as positive numbers. If you expand, sum goes up. If you shrink, sum goes down.\n\nBut if negative numbers are allowed (e.g., `[2, -10, 8, ...]`), expanding doesn\'t necessarily increase the sum, and shrinking doesn\'t necessarily decrease it. Then this simple sliding-window reasoning can break, and you may need **prefix sums, deque, binary search, etc.**\n\nSo your next-level mental model should be:\n1. What is the valid-window condition?\n2. What makes the window invalid?\n3. Once valid, do I want to expand or shrink?\n4. **Does adding/removing elements behave predictably enough for sliding window to work?**'
        }
      ]
    },
    {
      num: '19',
      title: 'Code Template (Java)',
      blocks: [
        {
          type: 'code',
          language: 'java',
              label: 'Variable Size — Minimum Size Subarray Sum',
              code: {
                java: `public int minSubArrayLen(int target, int[] nums) {
    int left = 0, sum = 0, minLen = Integer.MAX_VALUE;
    for (int right = 0; right < nums.length; right++) {
        sum += nums[right];
        while (sum >= target) { // while, not if — shrink as far as validity allows
            minLen = Math.min(minLen, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }
    return minLen == Integer.MAX_VALUE ? 0 : minLen;
}`,
                javascript: `function minSubArrayLen(target, nums) {
    let left = 0, sum = 0, minLen = Infinity;
    for (let right = 0; right < nums.length; right++) {
        sum += nums[right];
        while (sum >= target) { // while, not if — shrink as far as validity allows
            minLen = Math.min(minLen, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }
    return minLen == Infinity ? 0 : minLen;
}`
              },
        },
        {
          type: 'code',
          language: 'java',
              label: 'General-purpose variable-size skeleton',
              code: {
                java: `public int slidingWindowTemplate(int[] nums, int constraint) {
    int left = 0;
    int aggregate = 0; // swap for a Map<Character,Integer> etc. as needed
    int best = 0;

    for (int right = 0; right < nums.length; right++) {
        aggregate += nums[right]; // fold in new element

        while (/* aggregate violates constraint */ aggregate > constraint) {
            aggregate -= nums[left]; // fold out leftmost element
            left++;
        }

        best = Math.max(best, right - left + 1);
    }
    return best;
}`,
                javascript: `function slidingWindowTemplate(nums, constraint) {
    let left = 0;
    let aggregate = 0; // swap for a Map<Character,Integer> etc. as needed
    let best = 0;

    for (let right = 0; right < nums.length; right++) {
        aggregate += nums[right]; // fold in newfunction while(constraint) {
            aggregate -= nums[left]; // fold out leftmost element
            left++;
        }

        best = Math.max(best, right - left + 1);
    }
    return best;
}`
              },
        },
      ],
    },
    {
      num: '20',
      title: 'Interview Checklist',
      blocks: [
        {
          type: 'checklist',
          id: 'sliding-window-variable-checklist',
          items: [
            'Is the window size variable (I\'m optimizing the size itself, not given k)?',
            'Is my shrink condition monotonic — once invalid, does only shrinking fix it?',
            'Is the shrink step a `while` loop, not an `if`?',
            'Am I updating the aggregate incrementally (O(1) per shift)?',
            'Do I need a frequency map, or is a plain numeric aggregate enough?',
          ],
        },
      ],
    },
  ],
  conclusion: {
    title: '💡 Key takeaway',
    text: 'Variable-size sliding window is O(n) amortized because neither pointer ever moves backward. The shrink step must be a `while` loop — an `if` is the #1 bug on this pattern.',
  },
};

export default slidingWindowVariable;
