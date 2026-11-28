const slidingWindowFixed = {
  slug: 'sliding-window-fixed',
  eyebrow: 'Phase 2 — Sliding Window & Prefix Techniques',
  title: 'Sliding Window — Fixed Size',
  lede: 'A window is a contiguous slice of an array defined by a left and right boundary. The Fixed-Size variation keeps the window width constant at k — one element enters the right side exactly as one leaves the left side, maintaining the aggregate with just two operations per step.',
  overview: [
    { label: 'Time Complexity', value: 'O(N)' },
    { label: 'Space Complexity', value: 'O(1) auxiliary' },
    { label: 'Key Pattern', value: 'Slide, don\'t recompute' },
  ],
  sections: [
    {
      num: '01',
      title: 'What is it?',
      blocks: [
        {
          type: 'p',
          text: 'In the fixed-size variation, the window width `k` is given upfront. Rather than re-summing the entire window at each position, you **subtract the element leaving the left** and **add the element entering the right** — a constant-time update per shift.',
        },
        {
          type: 'callout',
          variant: 'teal',
          title: 'Core insight',
          text: 'Window [i, i+k) and [i+1, i+k+1) share k-1 elements. Recomputing the shared part is pure waste. The incremental update converts O(k) recomputation into O(1) per slide.',
        },
      ],
    },
    {
      num: '02',
      title: 'Why do we use it?',
      blocks: [
        {
          type: 'ul',
          items: [
            '**Problem it solves:** "What\'s the best aggregate over any contiguous segment of size k?" — brute force recomputes the whole segment each time, costing O(n·k) total.',
            '**What makes it better:** Converts "recompute the whole window" into "adjust the previous answer by one element" — same trick as prefix sums, applied to a moving segment.',
          ],
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
            '"subarray/substring of length k"',
            '"average of every window of size k"',
            '"maximum sum subarray of length k"',
            'Any problem where the window size is explicitly given as a constant.',
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
            'Build the aggregate (sum, count, etc.) for the **first window** `[0, k-1]` directly — this is the setup phase.',
            'Record the answer for that first window.',
            'Slide `right` from index `k` to the end: `aggregate += nums[right] - nums[right - k]`.',
            'Update the best answer after each slide.',
          ],
        },
        {
          type: 'callout',
          variant: 'rose',
          title: 'Common mistake',
          text: 'Forgetting to **build the initial window** before the sliding loop begins and instead trying to slide from an empty state — this causes an off-by-one at the very start.',
        },
      ],
    },
    {
      num: '05',
      title: 'Dry Run',
      titleSuffix: 'Maximum sum subarray of size k=3 in [2, 1, 5, 1, 3, 2]',
      blocks: [
        {
          type: 'table',
          headers: ['window', 'left', 'right', 'leaving', 'entering', 'sum calc', 'sum', 'max so far'],
          rows: [
            ['[2,1,5]', '0', '2', '—', '—', '2+1+5 (initial)', '8', '8'],
            ['[1,5,1]', '1', '3', '2', '1', '8 − 2 + 1', '7', '8'],
            ['[5,1,3]', '2', '4', '1', '3', '7 − 1 + 3', '9', '9'],
            ['[1,3,2]', '3', '5', '5', '2', '9 − 5 + 2', '6', '9'],
          ],
        },
        {
          type: 'p',
          text: 'Answer: **9** (window [5,1,3]). Only 2 arithmetic operations per slide vs. re-summing 3 elements each time — the gap widens fast as k grows.',
        },
      ],
    },
    {
      num: '06',
      title: 'Visual element Explanation',
      blocks: [
        {
          type: 'ascii',
          content: `[2, 1, 5, 1, 3, 2]
[■  ■  ■] .  .  .     sum=8
 .  [■  ■  ■] .  .    sum=8-2+1=7
 .  .  [■  ■  ■] .    sum=7-1+3=9  ← max
 .  .  .  [■  ■  ■]   sum=9-5+2=6

Window slides right by 1 each step, size stays fixed at k=3.`,
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
            '**All cases: O(n)** — every element enters the window exactly once and leaves at most once. No early exit exists.',
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
            '**O(1) auxiliary** — only two running scalars (the aggregate and best answer) are needed.',
            'Scales to O(k) or O(distinct elements) if the window tracks a frequency map instead of a plain number.',
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
            '**Forgetting to build the initial window** before sliding — the loop must start at index `k`, not `0`.',
            '**Recomputing the window from scratch** on every slide — technically correct, but silently degrades to O(n·k) and defeats the entire purpose.',
            '**Off-by-one on window boundaries** — is `right` inclusive or exclusive? Mixing conventions mid-solution is a frequent source of bugs.',
          ],
        },
      ],
    },
    {
      num: '11',
      title: 'Prerequisites',
      blocks: [
        {
          type: 'ul',
          items: [
            'Two Pointer mechanics (Sliding Window is a same-direction specialization).',
            'Comfort with "incremental update" thinking (add one, remove one) instead of recomputation.',
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
          text: 'Start from brute force: for every window position, sum k elements — O(n·k). Now notice: consecutive windows overlap almost entirely. The only new information in the next window is one element entering and one leaving. "Most of my answer didn\'t change, only the edges did" — this observation converts the recomputation into a single O(1) update.',
        },
      ],
    },
    {
      num: '19',
      title: 'Code Template (Java)',
      blocks: [
        {
          type: 'code',
          language: 'java',
              label: 'Fixed Size Window — Maximum Sum Subarray of Size k',
              code: {
                java: `public int maxSumSubarray(int[] nums, int k) {
    int windowSum = 0;
    for (int i = 0; i < k; i++) windowSum += nums[i]; // build initial window
    int maxSum = windowSum;

    for (int right = k; right < nums.length; right++) {
        windowSum += nums[right] - nums[right - k]; // add entering, remove leaving
        maxSum = Math.max(maxSum, windowSum);
    }
    return maxSum;
}`,
                javascript: `function maxSumSubarray(nums, k) {
    let windowSum = 0;
    for (let i = 0; i < k; i++) windowSum += nums[i]; // build initial window
    let maxSum = windowSum;

    for (let right = k; right < nums.length; right++) {
        windowSum += nums[right] - nums[right - k]; // add entering, remove leaving
        maxSum = Math.max(maxSum, windowSum);
    }
    return maxSum;
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
          id: 'sliding-window-fixed-checklist',
          items: [
            'Is the window size k explicitly fixed by the problem?',
            'Did I build the initial window before the sliding loop (not start from an empty state)?',
            'Am I updating the aggregate incrementally (O(1) per shift), not recomputing from scratch?',
            'Is the loop starting index correct (right starts at k, not 0)?',
          ],
        },
      ],
    },
  ],
  conclusion: {
    title: '💡 Key takeaway',
    text: 'Fixed-size sliding window turns O(n·k) recomputation into O(n) by maintaining a running aggregate updated in O(1) per step. Always build the first window before sliding.',
  },
};

export default slidingWindowFixed;
