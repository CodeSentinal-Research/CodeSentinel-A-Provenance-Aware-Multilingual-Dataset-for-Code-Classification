const dpSequence = {
  slug: 'dp-sequence',
  phaseId: '15',
  eyebrow: 'Phase 15 — Dynamic Programming',
  title: 'Sequence DP',
  lede: 'DP over one or two sequences (arrays/strings) where the state captures a position, and the transition compares elements — extending, matching, or skipping — based on whether they align. Same self-similar-subproblem idea as Knapsack, just with "position" as the state instead of "capacity".',

  overview: [
    { label: 'Time Complexity', value: 'O(n²) for LIS, O(m·n) for LCS/Edit Distance' },
    { label: 'Space Complexity', value: 'O(n) or O(m·n) (reducible to O(min(m,n)))' },
    { label: 'Optimization', value: 'O(n log n) for LIS via binary search (Patience Sorting)' },
  ],

  sections: [
    {
      num: '01',
      title: 'What Is It?',
      blocks: [
        {
          type: 'p',
          text: 'DP over one or two sequences (arrays/strings) where the state captures a **position** (or a pair of positions, for two-sequence problems), and the transition compares elements — extending, matching, or skipping — based on whether they align. This is the same self-similar-subproblem idea as Knapsack, just with "position in a sequence" as the state dimension instead of "remaining capacity."'
        }
      ]
    },
    {
      num: '02',
      title: 'Why Do We Use It?',
      blocks: [
        {
          type: 'ul',
          items: [
            '**Problem it solves:** naively enumerating every subsequence or every possible alignment between two strings is $O(2^n)$ — the number of subsequences of an `n`-length sequence.',
            '**Why it works:** "the best answer considering only the first `i` elements" (or `i` and `j` for two sequences) is a **polynomial**-sized set of distinct states — $O(n)$ or $O(m \\cdot n)$ — even though the number of *subsequences* is exponential. Memoizing on position collapses the search.',
            '**Efficiency:** $O(n^2)$ or $O(m \\cdot n)$ instead of exponential.'
          ]
        }
      ]
    },
    {
      num: '03',
      title: 'When Should I Think About Using It?',
      blocks: [
        {
          type: 'ul',
          items: [
            '"longest increasing subsequence"',
            '"longest common subsequence"',
            '"edit distance" / "minimum operations to convert one string to another"'
          ]
        }
      ]
    },
    {
      num: '04',
      title: 'How Does It Work?',
      blocks: [
        {
          type: 'ul',
          items: [
            '**Single-sequence (LIS):** `dp[i]` = length of the best subsequence **ending exactly at** index `i`. Transition: `dp[i] = max(dp[j] + 1)` for all `j < i` where `nums[j] < nums[i]`.',
            '**Two-sequence (LCS, Edit Distance):** `dp[i][j]` = the answer considering the first `i` characters of `s1` and first `j` characters of `s2`. Transition compares `s1[i-1]` vs. `s2[j-1]` — match or mismatch drives which smaller states get referenced.'
          ]
        }
      ]
    },
    {
      num: '05',
      title: 'Dry Run — Longest Increasing Subsequence',
      blocks: [
        {
          type: 'p',
          text: '**Problem:** `nums = [10,9,2,5,3,7,101,18]`.\n`dp[i] = 1` initially (every single element is trivially an increasing subsequence of length 1).'
        },
        {
          type: 'table',
          headers: ['i', 'nums[i]', 'best j<i with nums[j]<nums[i]', 'dp[i]'],
          rows: [
            ['0', '10', '—', '1'],
            ['1', '9', 'none (10 ≥ 9)', '1'],
            ['2', '2', 'none', '1'],
            ['3', '5', 'j=2 (2<5) → dp[2]+1=2', '2'],
            ['4', '3', 'j=2 (2<3) → dp[2]+1=2', '2'],
            ['5', '7', 'j=3 or j=4 (5<7, 3<7) → max(dp[3],dp[4])+1=3', '3'],
            ['6', '101', 'j=5 (7<101) → dp[5]+1=4', '4'],
            ['7', '18', 'j=5 (7<18, best among valid j) → dp[5]+1=4', '4']
          ]
        },
        {
          type: 'p',
          text: '`dp = [1,1,1,2,2,3,4,4]`, **answer = max(dp) = 4** — matching subsequence `[2,5,7,101]` or `[2,3,7,18]`.'
        }
      ]
    },
    {
      num: '06',
      title: 'Visual Element Explanation',
      blocks: [
        {
          type: 'ascii',
          content: `nums: 10  9  2  5  3  7  101  18
dp:    1  1  1  2  2  3   4    4
                          ↑
              max across ALL dp[i] — NOT just dp[last]! 4 is achieved
              at index 6, not necessarily the final position.`
        }
      ]
    },
    {
      num: '10',
      title: 'The Catch ⭐',
      blocks: [
        {
          type: 'ul',
          items: [
            '**`dp[i]` means "LIS ENDING AT `i`," not "LIS considering the first `i` elements"** — this exact state-definition confusion is the most common bug.',
            '**The final answer is `max(dp[])` over ALL indices, not `dp[n-1]`** — the true LIS may not end at the array\'s last element at all.',
            '**The O(n log n) optimization changes the state representation entirely** (tracking the smallest achievable *tail value* per length). Reconstructing the actual sequence requires extra parent pointers.'
          ]
        }
      ]
    },
    {
      num: '12',
      title: 'Examples',
      blocks: [
        {
          type: 'collapse',
          title: 'i) LIS (Longest Increasing Subsequence)',
          tag: 'O(n²) standard | O(n log n) optimized',
          defaultOpen: true,
          blocks: [
            {
              type: 'code',
              language: 'java',
              label: 'LIS — O(n²) (Java)',
              code: {
                java: `public int lengthOfLIS(int[] nums) {
    int[] dp = new int[nums.length];
    Arrays.fill(dp, 1);
    int maxLen = 1;
    for (int i = 1; i < nums.length; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) dp[i] = Math.max(dp[i], dp[j] + 1);
        }
        maxLen = Math.max(maxLen, dp[i]); // track RUNNING max
    }
    return maxLen;
}`,
                javascript: `function lengthOfLIS(nums) {
    int[] dp = new Array(nums.length).fill(0);
    Arrays.fill(dp, 1);
    let maxLen = 1;
    for (let i = 1; i < nums.length; i++) {
        for (let j = 0; j < i; j++) {
            if (nums[j] < nums[i]) dp[i] = Math.max(dp[i], dp[j] + 1);
        }
        maxLen = Math.max(maxLen, dp[i]); // track RUNNING max
    }
    return maxLen;
}`
              }
            },
            {
              type: 'code',
              language: 'java',
              label: 'LIS — O(n log n) (Java)',
              code: {
                java: `public int lengthOfLISOptimized(int[] nums) {
    List<Integer> tails = new ArrayList<>();
    for (int num : nums) {
        int pos = Collections.binarySearch(tails, num);
        if (pos < 0) pos = -(pos + 1); // insertion point
        if (pos == tails.size()) tails.add(num);
        else tails.set(pos, num);
    }
    return tails.size();
}`,
                javascript: `function lengthOfLISOptimized(nums) {
    const tails = [];
    for (const num of nums) {
        let pos = Collections.binarySearch(tails, num);
        if (pos < 0) pos = -(pos + 1); // insertion point
        if (pos == tails.length) tails.push(num);
        else tails.set(pos, num);
    }
    return tails.length;
}`
              }
            }
          ]
        },
        {
          type: 'collapse',
          title: 'ii) Longest Common Subsequence (LCS)',
          tag: 'O(m·n) | Unconditional Match Transition',
          defaultOpen: false,
          blocks: [
            {
              type: 'p',
              text: '**The Catch:** On a match, transition is unconditional (`dp[i-1][j-1]+1`), no comparison needed against skip options. On mismatch, take `max` of skipping either character.'
            },
            {
              type: 'code',
              language: 'java',
              label: 'LCS (Java)',
              code: {
                java: `public int longestCommonSubsequence(String s1, String s2) {
    int m = s1.length(), n = s2.length();
    int[][] dp = new int[m + 1][n + 1];
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                dp[i][j] = dp[i - 1][j - 1] + 1; // match — unconditional
            } else {
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]); // mismatch — skip either
            }
        }
    }
    return dp[m][n];
}`,
                javascript: `function longestCommonSubsequence(s1, s2) {
    let m = s1.length(), n = s2.length();
    int[][] dp = Array.from({length: m + 1}, () => new Array(n + 1).fill(0));
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1; // match — unconditional
            } else {
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]); // mismatch — skip either
            }
        }
    }
    return dp[m][n];
}`
              }
            }
          ]
        },
        {
          type: 'collapse',
          title: 'iii) Edit Distance (Levenshtein)',
          tag: 'O(m·n) | Insert / Delete / Replace',
          defaultOpen: false,
          blocks: [
            {
              type: 'p',
              text: '**Base cases:** `dp[i][0]=i` (delete all), `dp[0][j]=j` (insert all). Crucial for correctly handling conversion to/from empty strings.'
            },
            {
              type: 'code',
              language: 'java',
              label: 'Edit Distance (Java)',
              code: {
                java: `public int minDistance(String s1, String s2) {
    int m = s1.length(), n = s2.length();
    int[][] dp = new int[m + 1][n + 1];
    for (int i = 0; i <= m; i++) dp[i][0] = i; // delete all
    for (int j = 0; j <= n; j++) dp[0][j] = j; // insert all

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                dp[i][j] = dp[i - 1][j - 1]; // no edit needed
            } else {
                dp[i][j] = 1 + Math.min(dp[i - 1][j - 1],  // replace
                                 Math.min(dp[i - 1][j],      // delete
                                          dp[i][j - 1]));    // insert
            }
        }
    }
    return dp[m][n];
}`,
                javascript: `function minDistance(s1, s2) {
    let m = s1.length(), n = s2.length();
    int[][] dp = Array.from({length: m + 1}, () => new Array(n + 1).fill(0));
    for (let i = 0; i <= m; i++) dp[i][0] = i; // delete all
    for (let j = 0; j <= n; j++) dp[0][j] = j; // insertfunction for(i++) {
        for (let j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // no edit needed
            } else {
                dp[i][j] = 1 + Math.min(dp[i - 1][j - 1],  // replace
                                 Math.min(dp[i - 1][j],      // delete
                                          dp[i][j - 1]));    // insert
            }
        }
    }
    return dp[m][n];
}`
              }
            }
          ]
        }
      ]
    },
    {
      num: '20',
      title: 'Interview Checklist',
      blocks: [
        {
          type: 'checklist',
          id: 'dp-sequence-checklist',
          items: [
            'Single sequence (1D state) or two sequences (2D state)?',
            'LIS-style: is the answer `max(dp[])` across all positions, not just `dp[last]`?',
            'Two-sequence: on a match, is the transition unconditional?',
            'Do I need just the length/count, or the actual reconstructed sequence?',
            'For LIS: does input size justify the O(n log n) optimization?'
          ]
        }
      ]
    }
  ],
  conclusion: {
    title: '💡 Key takeaway',
    text: 'Sequence DP answers "what is the best way to align, compare, or extend at this position?" The key realization is that answering this for position `i` only ever needs the best answers for smaller prefixes.'
  }
};

export default dpSequence;
