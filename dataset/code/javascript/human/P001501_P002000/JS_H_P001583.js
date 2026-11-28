const kadanes = {
  slug: 'kadanes',
  eyebrow: 'Phase 2 — Sliding Window & Prefix Techniques',
  title: "Kadane's / Subarray",
  lede: "Kadane's family solves \"find the optimal contiguous subarray\" problems with a single linear pass, by maintaining a running \"best value ending exactly here\" and deciding at each element whether to extend the previous subarray or abandon it and start fresh.",
  overview: [
    { label: 'Time Complexity', value: 'O(N) — all cases' },
    { label: 'Space Complexity', value: 'O(1) auxiliary' },
    { label: 'Decision Rule', value: 'Extend or restart' },
  ],
  sections: [
    {
      num: '01',
      title: 'What is it?',
      blocks: [
        {
          type: 'p',
          text: "Kadane's algorithm maintains two running values: `currentBest` (best result ending exactly at the current index) and `globalBest` (best result seen anywhere so far). At each element it makes one greedy decision: extend the previous subarray, or start fresh here.",
        },
        {
          type: 'complexity',
          items: [
            { label: 'Core recurrence', value: 'currentBest = max(arr[i], currentBest + arr[i])', small: true },
          ],
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
            '**Problem it solves:** brute force for "max sum contiguous subarray" tries every (start, end) pair — O(n²).',
            '**Key insight:** the best subarray ending at position `i` only depends on the best ending at `i-1`. Either extend it or restart — a decision made in O(1) at each step.',
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
            '"maximum subarray sum" / "maximum contiguous sum"',
            '"maximum product subarray"',
            '"largest sum of a contiguous run"',
            'Arrays containing negative numbers where a naive "add everything" approach fails.',
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
            'Initialize `currentBest = arr[0]`, `globalBest = arr[0]`.',
            'For each element from index 1 onward:',
            '  `currentBest = max(arr[i], currentBest + arr[i])` — extend or restart.',
            '  `globalBest = max(globalBest, currentBest)` — track the overall best.',
            'Return `globalBest`.',
          ],
        },
      ],
    },
    {
      num: '05',
      title: 'Dry Run',
      titleSuffix: 'Max Subarray Sum — arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]',
      blocks: [
        {
          type: 'table',
          headers: ['i', 'num', 'extend (cB+num)', 'restart (num)', 'currentBest', 'decision', 'globalBest'],
          rows: [
            ['0', '-2', '—', '-2', '-2', 'start', '-2'],
            ['1', '1', '-1', '1', '1', 'restart (1 > -1)', '1'],
            ['2', '-3', '-2', '-3', '-2', 'extend (-2 > -3)', '1'],
            ['3', '4', '2', '4', '4', 'restart (4 > 2)', '4'],
            ['4', '-1', '3', '-1', '3', 'extend (3 > -1)', '4'],
            ['5', '2', '5', '2', '5', 'extend (5 > 2)', '5'],
            ['6', '1', '6', '1', '6', 'extend (6 > 1)', '6'],
            ['7', '-5', '1', '-5', '1', 'extend (1 > -5)', '6'],
            ['8', '4', '5', '4', '5', 'extend (5 > 4)', '6'],
          ],
        },
        {
          type: 'p',
          text: 'Answer: **6** (subarray [4, -1, 2, 1]). Only one comparison and one addition per element — the whole array examined exactly once.',
        },
      ],
    },
    {
      num: '06',
      title: 'Visual element Explanation',
      blocks: [
        {
          type: 'ascii',
          content: `arr:         -2   1  -3   4  -1   2   1  -5   4
currentBest: -2   1  -2   4   3   5   6   1   5
                  ↑restart  ↑restart
globalBest:  -2   1   1   4   4   5   6   6   6
                                              └── final answer

Whenever currentBest dips below a fresh restart,
the algorithm "resets" — the running line starts over
rather than dragging a negative deficit forward.`,
        },
      ],
    },
    {
      num: '07',
      title: 'Time Complexity',
      blocks: [
        {
          type: 'p',
          text: '**O(n) — all cases.** No early exit, no case that degrades. Every element is visited exactly once with O(1) work (one addition, two comparisons).',
        },
      ],
    },
    {
      num: '08',
      title: 'Space Complexity',
      blocks: [
        {
          type: 'p',
          text: '**O(1) auxiliary** — just two running scalars (`currentBest`, `globalBest`). No arrays, no recursion stack.',
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
            '**Initializing `globalBest = 0`** — silent bug on all-negative arrays. The answer (least-negative element) never beats 0. Always initialize to `arr[0]`.',
            '**"Reset to 0 when negative"** shortcut — correct only if an empty subarray (sum 0) is allowed. For the standard non-empty requirement, compare `arr[i]` vs `currentBest + arr[i]` directly.',
            '**Recovering the actual subarray** requires tracking a separate start index updated only on restart events.',
            '**Doesn\'t extend directly to products** — multiplying by a negative flips sign, requiring a dual min/max tracking (see Variation ii).',
            '**Interview trap:** stating the algorithm correctly but tripping on the all-negative edge case when asked. Walk through it explicitly.',
          ],
        },
      ],
    },
    {
      num: '12',
      title: 'Variations',
      blocks: [
        {
          type: 'p',
          text: 'Three distinct problems in the Kadane\'s family, each with a specific twist:',
        },
      ],
    },
    {
      num: '12a',
      title: 'Variation i — Max Product Subarray',
      blocks: [
        {
          type: 'p',
          text: 'Multiplying by a negative flips the sign — a deeply negative running product can become the maximum when multiplied by another negative. Track both a `curMax` **and** a `curMin` at every step.',
        },
        {
          type: 'p',
          text: '**Dry run:** `nums = [2, 3, -2, 4, -1]`',
        },
        {
          type: 'table',
          headers: ['i', 'num', 'curMax·num', 'curMin·num', 'candidates', 'curMax', 'curMin', 'globalMax'],
          rows: [
            ['0', '2', '—', '—', '—', '2', '2', '2'],
            ['1', '3', '6', '6', '{3,6,6}', '6', '3', '6'],
            ['2', '-2', '-12', '-6', '{-2,-12,-6}', '-2', '-12', '6'],
            ['3', '4', '-8', '-48', '{4,-8,-48}', '4', '-48', '6'],
            ['4', '-1', '-4', '48', '{-1,-4,48}', '48', '-4', '48'],
          ],
        },
        {
          type: 'p',
          text: 'Answer: **48** (entire array: 2·3·(-2)·4·(-1) = 48). `curMin` carried -48 precisely so that multiplying by -1 could flip it to 48.',
        },
        {
          type: 'callout',
          variant: 'rose',
          title: 'The defining bug',
          text: 'Tracking only `curMax` (forgetting `curMin`) passes simple positive-only tests and silently fails the moment a double-negative flip appears — exactly the case interviewers use to test deep understanding.',
        },
        {
          type: 'code',
          language: 'java',
              label: 'Max Product Subarray',
              code: {
                java: `public int maxProduct(int[] nums) {
    int curMax = nums[0], curMin = nums[0], result = nums[0];
    for (int i = 1; i < nums.length; i++) {
        int num = nums[i];
        int candidateMax = Math.max(num, Math.max(curMax * num, curMin * num));
        int candidateMin = Math.min(num, Math.min(curMax * num, curMin * num));
        curMax = candidateMax;
        curMin = candidateMin;
        result = Math.max(result, curMax);
    }
    return result;
}`,
                javascript: `function maxProduct(nums) {
    let curMax = nums[0], curMin = nums[0], result = nums[0];
    for (let i = 1; i < nums.length; i++) {
        let num = nums[i];
        let candidateMax = Math.max(num, Math.max(curMax * num, curMin * num));
        let candidateMin = Math.min(num, Math.min(curMax * num, curMin * num));
        curMax = candidateMax;
        curMin = candidateMin;
        result = Math.max(result, curMax);
    }
    return result;
}`
              },
        },
      ],
    },
    {
      num: '12b',
      title: 'Variation ii — Longest Subarray with Given Sum (Prefix + Hash Map)',
      blocks: [
        {
          type: 'p',
          text: 'When asked for the **longest** subarray summing to target `k`, the hash map stores the **first index** each prefix sum occurred at (not a count) — maximizing the span from the earliest possible start.',
        },
        {
          type: 'p',
          text: '**Dry run:** `nums = [1, -1, 5, -2, 3]`, `k = 3` → longest subarray summing to 3.',
        },
        {
          type: 'table',
          headers: ['i', 'num', 'prefixSum', 'need (sum-k)', 'in map at idx?', 'length', 'maxLen'],
          rows: [
            ['—', 'seed', '0', '—', 'pre-seeded → -1', '—', '0'],
            ['0', '1', '1', '-2', 'no', '—', '0'],
            ['1', '-1', '0', '-3', 'no (keep first: -1)', '—', '0'],
            ['2', '5', '5', '2', 'no', '—', '0'],
            ['3', '-2', '3', '0', 'yes at -1', '3-(-1)=4', '4'],
            ['4', '3', '6', '3', 'yes at 3', '4-3=1', '4'],
          ],
        },
        {
          type: 'p',
          text: 'Answer: **4** (subarray `[1,-1,5,-2]`, indices 0-3).',
        },
        {
          type: 'code',
          language: 'java',
              label: 'Longest Subarray with Given Sum',
              code: {
                java: `public int longestSubarraySum(int[] nums, int k) {
    Map<Integer, Integer> firstIndex = new HashMap<>();
    firstIndex.put(0, -1); // prefix sum 0 occurs before the array starts
    int prefixSum = 0, maxLen = 0;

    for (int i = 0; i < nums.length; i++) {
        prefixSum += nums[i];
        if (firstIndex.containsKey(prefixSum - k)) {
            maxLen = Math.max(maxLen, i - firstIndex.get(prefixSum - k));
        }
        firstIndex.putIfAbsent(prefixSum, i); // keep earliest index only
    }
    return maxLen;
}`,
                javascript: `function longestSubarraySum(nums, k) {
    const firstIndex = new Map();
    firstIndex.set(0, -1); // prefix sum 0 occurs before the array starts
    let prefixSum = 0, maxLen = 0;

    for (let i = 0; i < nums.length; i++) {
        prefixSum += nums[i];
        if (firstIndex.has(prefixSum - k)) {
            maxLen = Math.max(maxLen, i - firstIndex[prefixSum - k]);
        }
        firstIndex.putIfAbsent(prefixSum, i); // keep earliest index only
    }
    return maxLen;
}`
              },
        },
      ],
    },
    {
      num: '13',
      title: 'Related Patterns',
      blocks: [
        {
          type: 'chain',
          nodes: [
            { label: "Kadane's / Subarray", desc: 'Optimize running max/min, negatives allowed', current: true },
            { label: 'Prefix Sum + Hash Map', desc: 'Count/locate subarrays matching an exact target' },
            { label: 'Dynamic Programming', desc: "Kadane's is 1D DP with O(1) space — previews Phase 15" },
            { label: 'Sliding Window', desc: 'Contrast: requires non-negative values to shrink correctly' },
          ],
          arrows: ['pivot to counting exact targets', 'full DP generalization', 'alternative for non-negative arrays'],
        },
      ],
    },
    {
      num: '17',
      title: 'Intuition',
      blocks: [
        {
          type: 'p',
          text: "The best subarray ending at position `i` can only be one of two things: the single element `arr[i]` alone, or `arr[i]` tacked onto the best subarray ending at `i-1`. There's no third option. That's the entire algorithm — a greedy local decision that produces the global optimum because the recurrence only ever depends on the single previous result.",
        },
      ],
    },
    {
      num: '18',
      title: 'Pseudocode',
      blocks: [
        {
          type: 'code',
          language: 'python',
          code: `function kadanesMaxSum(array):
    currentBest = array[0]
    globalBest = array[0]

    for i from 1 to length(array) - 1:
        currentBest = max(array[i], currentBest + array[i])
        globalBest = max(globalBest, currentBest)

    return globalBest`,
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
          label: "Kadane's — Max Subarray Sum",
          code: `public int maxSubArray(int[] nums) {
    int currentBest = nums[0], globalBest = nums[0];
    for (int i = 1; i < nums.length; i++) {
        currentBest = Math.max(nums[i], currentBest + nums[i]);
        globalBest = Math.max(globalBest, currentBest);
    }
    return globalBest;
}`,
        },
      ],
    },
    {
      num: '20',
      title: 'Interview Checklist',
      blocks: [
        {
          type: 'checklist',
          id: 'kadanes-checklist',
          items: [
            'Did I initialize both running values to `arr[0]`, not 0?',
            'Am I optimizing a product (not a sum)? → track both curMax AND curMin.',
            'Does the problem allow an empty subarray? (Changes whether to clamp at 0 or not.)',
            'Do I need to return the actual subarray (not just its sum)? → track a start index updated only on restart.',
            'Is the problem actually about counting/finding subarrays matching a target? → that\'s Prefix Sum + Hash Map.',
            'Did I walk through the all-negative edge case explicitly?',
          ],
        },
      ],
    },
  ],
  conclusion: {
    title: '💡 Key takeaway',
    text: "Kadane's achieves O(n) / O(1) by making one greedy decision per element: extend or restart. Initialize to arr[0] (never 0). For products, track both curMax and curMin. For exact-target subarrays, pivot to Prefix Sum + Hash Map.",
  },
};

export default kadanes;
