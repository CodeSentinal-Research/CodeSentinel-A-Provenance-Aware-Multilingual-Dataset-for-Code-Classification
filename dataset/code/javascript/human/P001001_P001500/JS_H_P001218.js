const dpPartition = {
  slug: 'dp-partition',
  phaseId: '15',
  eyebrow: 'Phase 15 — Dynamic Programming',
  title: 'Partition DP',
  lede: 'DP that splits a sequence into optimal contiguous partitions. The state dp[i] represents the best answer for the prefix of length i; the transition tries every possible position of the last cut j < i, combining dp[j] with the cost/validity of the final segment s[j..i).',

  overview: [
    { label: 'Time Complexity', value: 'O(n²) — n states, up to n candidate cuts each' },
    { label: 'Space Complexity', value: 'O(n) for 1D dp array, often + O(n²) for precomputation' },
    { label: 'Key characteristic', value: 'Transition checks ALL valid j < i, not just i-1' },
  ],

  sections: [
    {
      num: '01',
      title: 'What Is It?',
      blocks: [
        {
          type: 'p',
          text: 'DP that splits a sequence into optimal contiguous **partitions** (segments). The state `dp[i]` represents the best answer for the prefix of length `i`; the transition tries **every possible position of the last cut** `j < i`, combining `dp[j]` with the cost/validity of the final segment `s[j..i)`.'
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
            '**Problem it solves:** naively trying every possible way to place cuts in a sequence of length `n` is exponential — completely infeasible.',
            '**Why it works:** the best way to partition a prefix of length `i` only depends on `dp[j]` for smaller `j` — there are only $O(n)$ distinct prefix states.',
            '**Efficiency:** $O(n^2)$ instead of exponential cut-placement enumeration.'
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
            '"minimum cuts to partition into palindromes"',
            '"word break" (can a string be segmented into dictionary words)',
            '"perfect squares" (minimum perfect squares summing to n)'
          ]
        }
      ]
    },
    {
      num: '04',
      title: 'How Does It Work?',
      blocks: [
        {
          type: 'p',
          text: '`dp[i]` = best answer for the prefix of length `i`. Transition: `dp[i] = best over all valid j < i of combine(dp[j], cost of segment s[j..i))`. This differs from Sequence DP\'s "extend or don\'t extend" binary choice — Partition DP considers **all** possible previous cut positions.'
        }
      ]
    },
    {
      num: '05',
      title: 'Dry Run — Palindrome Partitioning II',
      blocks: [
        {
          type: 'p',
          text: '**Problem:** `s = "aab"`. Find the minimum cuts so every resulting substring is a palindrome.\nConvention: `dp[0] = -1` (empty prefix needs "-1" cut so a whole-prefix palindrome costs 0).'
        },
        {
          type: 'table',
          headers: ['i', 'candidate last cuts j', 'is s[j..i) palindrome?', 'dp[i]'],
          rows: [
            ['1', 'j=0: "a"', 'yes (dp[0]+1=0)', '**0**'],
            ['2', 'j=0: "aa" (yes, 0); j=1: "a" (yes, dp[1]+1=1)', '—', '**0**'],
            ['3', 'j=0:"aab"(NO); j=1:"ab"(NO); j=2:"b"(yes, dp[2]+1=1)', '—', '**1**']
          ]
        },
        {
          type: 'p',
          text: '**Result: `dp[3] = 1`** — one cut needed: `"aa" | "b"`.'
        }
      ]
    },
    {
      num: '06',
      title: 'Visual Element Explanation',
      blocks: [
        {
          type: 'ascii',
          content: `s = a a b
    └┬┘ └┬┘
   "aa"  "b"   ← 1 cut, both segments are palindromes

dp[3] tries EVERY possible last-cut position:
  cut before 3 entirely ("aab" whole) → not palindrome
  cut at 1 ("ab" last segment) → not palindrome
  cut at 2 ("b" last segment) → IS palindrome → dp[2]+1 = 0+1 = 1 ✓`
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
            '**Precomputing validity (e.g. palindrome table) is essential for the $O(n^2)$ bound.** Doing O(n) naive checks inside the inner loop degrades to $O(n^3)$.',
            '**The precomputation table must be filled by increasing substring length.**',
            '**`dp[i]` must check ALL valid `j`**, not stop at the first one found.'
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
          title: 'i) Palindrome Partitioning II',
          tag: 'O(n²) | Min Cuts | Precomputed Palindrome Table',
          defaultOpen: true,
          blocks: [
            {
              type: 'code',
              language: 'java',
              label: 'Min Cuts (Java)',
              code: {
                java: `public int minCut(String s) {
    int n = s.length();
    boolean[][] isPalindrome = new boolean[n][n];
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            if (s.charAt(i) == s.charAt(j) && (len <= 2 || isPalindrome[i + 1][j - 1])) {
                isPalindrome[i][j] = true;
            }
        }
    }

    int[] dp = new int[n + 1];
    dp[0] = -1;
    for (int i = 1; i <= n; i++) {
        dp[i] = i - 1; // worst case
        for (int j = 0; j < i; j++) {
            if (isPalindrome[j][i - 1]) {
                dp[i] = Math.min(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[n];
}`,
                javascript: `function minCut(s) {
    let n = s.length();
    boolean[][] isPalindrome = Array.from({length: n}, () => new Array(n).fill(false));
    for (let len = 1; len <= n; len++) {
        for (let i = 0; i + len - 1 < n; i++) {
            let j = i + len - 1;
            if (s[i] == s[j] && (len <= 2 || isPalindrome[i + 1][j - 1])) {
                isPalindrome[i][j] = true;
            }
        }
    }

    int[] dp = new Array(n + 1).fill(0);
    dp[0] = -1;
    for (let i = 1; i <= n; i++) {
        dp[i] = i - 1; // worstfunction for(j++) {
            if (isPalindrome[j][i - 1]) {
                dp[i] = Math.min(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[n];
}`
              }
            }
          ]
        },
        {
          type: 'collapse',
          title: 'ii) Word Break',
          tag: 'O(n²) | Boolean DP',
          defaultOpen: false,
          blocks: [
            {
              type: 'code',
              language: 'java',
              label: 'Word Break (Java)',
              code: {
                java: `public boolean wordBreak(String s, List<String> wordDict) {
    Set<String> dict = new HashSet<>(wordDict);
    int n = s.length();
    boolean[] dp = new boolean[n + 1];
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && dict.contains(s.substring(j, i))) { // dp[j] checked FIRST
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}`,
                javascript: `function wordBreak(s, wordDict) {
    const dict = new Set(wordDict);
    let n = s.length();
    boolean[] dp = new Array(n + 1).fill(false);
    dp[0] = true;
    for (let i = 1; i <= n; i++) {
        for (let j = 0; j < i; j++) {
            if (dp[j] && dict.has(s.substring(j, i))) { // dp[j] checked FIRST
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}`
              }
            }
          ]
        },
        {
          type: 'collapse',
          title: 'iii) Perfect Squares',
          tag: 'O(n√n) | Unbounded Knapsack Reskin',
          defaultOpen: false,
          blocks: [
            {
              type: 'p',
              text: 'Structurally unbounded Knapsack in disguise (each perfect square is a reusable "coin", minimizing count).'
            },
            {
              type: 'code',
              language: 'java',
              label: 'Perfect Squares (Java)',
              code: {
                java: `public int numSquares(int n) {
    int[] dp = new int[n + 1];
    Arrays.fill(dp, Integer.MAX_VALUE);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int square = 1; square * square <= i; square++) {
            dp[i] = Math.min(dp[i], dp[i - square * square] + 1);
        }
    }
    return dp[n];
}`,
                javascript: `function numSquares(n) {
    int[] dp = new Array(n + 1).fill(0);
    Arrays.fill(dp, Infinity);
    dp[0] = 0;
    for (let i = 1; i <= n; i++) {
        for (let square = 1; square * square <= i; square++) {
            dp[i] = Math.min(dp[i], dp[i - square * square] + 1);
        }
    }
    return dp[n];
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
          id: 'dp-partition-checklist',
          items: [
            'Does the transition check EVERY possible last-cut position j?',
            'Is there a sub-DP (like palindrome checking) that needs precomputation?',
            'Word Break: am I checking `dp[j]` is true BEFORE testing the substring?',
            'Could this be a reskin of Knapsack (like Perfect Squares)?'
          ]
        }
      ]
    }
  ],
  conclusion: {
    title: '💡 Key takeaway',
    text: 'Partition DP asks: "what is the best way to make my last cut?" It considers all possible previous cut points, giving it an O(n) inner loop per state (often leading to O(n²) total time).'
  }
};

export default dpPartition;
