const prefixXorBits = {
  slug: 'prefix-xor-bits',
  phaseId: '12',
  eyebrow: 'Phase 12 — Bit Manipulation (Part 5)',
  title: 'Prefix XOR',
  lede: 'Using a prefix XOR array where prefix[i] = nums[0] ^ nums[1] ^ ... ^ nums[i-1] to answer range XOR queries in O(1) and find subarray XOR patterns. The range formula prefix[r+1] ^ prefix[l] directly mirrors prefix sum\'s subtraction, but uses XOR\'s self-inverse property instead.',

  overview: [
    { label: 'Build', value: 'O(n) — one pass to compute prefix XOR array' },
    { label: 'Range Query', value: 'O(1) — prefix[r+1] ^ prefix[l]' },
    { label: 'Key Property', value: 'XOR is its own inverse: a ^ a = 0, so prefix[r+1] ^ prefix[l] cancels everything outside [l..r]' },
  ],

  sections: [
    {
      num: '01',
      title: 'What Is It?',
      blocks: [
        {
          type: 'p',
          text: '**Context:** this pattern was first covered in depth in **Phase 2 → Prefix Based → Prefix XOR**, including the full range-query formula and dry run. This page is the Bit Manipulation perspective on it — connecting it to the XOR identities from the rest of Phase 12.'
        },
        {
          type: 'p',
          text: 'A **prefix XOR array** `prefix[i]` stores the XOR of all elements from `nums[0]` up to `nums[i-1]`. This lets you compute the XOR of any subarray `nums[l..r]` in **O(1)** using the formula: `prefix[r+1] ^ prefix[l]`.'
        }
      ]
    },
    {
      num: '02',
      title: 'Why It Works — The XOR Self-Inverse Property',
      blocks: [
        {
          type: 'callout',
          variant: 'teal',
          title: 'Why prefix[r+1] ^ prefix[l] Gives the Range XOR',
          text: '`prefix[r+1]` = `nums[0] ^ nums[1] ^ ... ^ nums[r]`\n\n`prefix[l]` = `nums[0] ^ nums[1] ^ ... ^ nums[l-1]`\n\nXOR-ing them: the elements `nums[0]` through `nums[l-1]` appear in BOTH — and `a ^ a = 0`, so they cancel perfectly. What remains is exactly `nums[l] ^ nums[l+1] ^ ... ^ nums[r]`.\n\nThis is the exact same "cancel the prefix" logic as prefix sums, but using XOR\'s self-inverse instead of subtraction.'
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
            '"XOR of elements in range [l, r]" / "subarray XOR queries"',
            '"count subarrays with XOR equal to k" (use a HashMap of prefix XOR counts)',
            '"find subarray with XOR = target" (same shape as subarray-sum = target from Phase 2)',
            '"maximum XOR of a subarray" (combine with Bitwise Trie — Phase 11)'
          ]
        }
      ]
    },
    {
      num: '05',
      title: 'Dry Run',
      blocks: [
        {
          type: 'p',
          text: '**Problem:** `nums = [3, 2, 4, 6, 1]`. Build the prefix XOR array, then answer range queries in O(1).'
        },
        {
          type: 'p',
          text: '**Build prefix XOR:**'
        },
        {
          type: 'table',
          headers: ['i', 'nums[i]', 'prefix[i+1]', 'binary'],
          rows: [
            ['—', '—', '`prefix[0] = 0`', '`000`'],
            ['0', '3', '`0 ^ 3 = 3`', '`011`'],
            ['1', '2', '`3 ^ 2 = 1`', '`001`'],
            ['2', '4', '`1 ^ 4 = 5`', '`101`'],
            ['3', '6', '`5 ^ 6 = 3`', '`011`'],
            ['4', '1', '`3 ^ 1 = 2`', '`010`']
          ]
        },
        {
          type: 'p',
          text: '**Query: XOR of `nums[1..3]` (elements 2, 4, 6):**\n`prefix[4] ^ prefix[1] = 3 ^ 3 = 0`\n\nVerify: `2 ^ 4 ^ 6 = 6 ^ 6 = 0` ✓\n\n**Query: XOR of `nums[0..2]` (elements 3, 2, 4):**\n`prefix[3] ^ prefix[0] = 5 ^ 0 = 5`\n\nVerify: `3 ^ 2 ^ 4 = 1 ^ 4 = 5` ✓'
        }
      ]
    },
    {
      num: '06',
      title: 'Visual Element Explanation',
      blocks: [
        {
          type: 'ascii',
          content: `Prefix XOR array (length n+1, 0-indexed, prefix[0] = 0):

nums:    3    2    4    6    1
prefix:  0    3    1    5    3    2
         |    |              |    |
         l=0  l=1            r+1  

Range [1..3]:  prefix[4] ^ prefix[1] = 3 ^ 3 = 0
               ↑ prefix[r+1]    ↑ prefix[l]

The elements in [0..0] (i.e., just 3) appear in BOTH prefix[4] and prefix[1]:
  prefix[4] = 3 ^ 2 ^ 4 ^ 6 = ...
  prefix[1] = 3
  XOR-ing cancels the 3, leaving 2 ^ 4 ^ 6 = 0 ✓`
        }
      ]
    },
    {
      num: '07',
      title: 'Time & Space Complexity',
      blocks: [
        {
          type: 'p',
          text: '**Build:** O(n) — one pass.\n\n**Range Query:** O(1) — two array lookups and one XOR.\n\n**Space:** O(n) for the prefix array.'
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
            '**Off-by-one: the formula is `prefix[r+1] ^ prefix[l]`, not `prefix[r] ^ prefix[l-1]`.** Getting this backwards is the most common bug. Using a 1-indexed prefix array with `prefix[0] = 0` as a sentinel avoids boundary-case conditionals.',
            '**XOR is its own inverse** — you "cancel" the unwanted prefix via XOR, not subtraction. There is no "negative XOR" — this isn\'t arithmetic subtraction, it\'s self-cancellation.',
            '**Counting subarrays with XOR = k:** uses `HashMap<Integer, Integer>` to count occurrences of each prefix XOR seen so far — `currentXOR ^ k` tells you the prefix XOR value you need to have seen before, giving O(n) time total. The exact pattern mirrors subarray-sum = target from Phase 2.'
          ]
        }
      ]
    },
    {
      num: '12',
      title: 'Code Templates',
      blocks: [
        {
          type: 'collapse',
          title: 'i) Build Prefix XOR + Range Query',
          tag: 'O(n) build | O(1) query | Standard pattern',
          defaultOpen: true,
          blocks: [
            {
              type: 'code',
              language: 'java',
              label: 'Prefix XOR Range Query (Java)',
              code: {
                java: `public int[] buildPrefixXOR(int[] nums) {
    int n = nums.length;
    int[] prefix = new int[n + 1]; // prefix[0] = 0 (sentinel)
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] ^ nums[i];
    }
    return prefix;
}

// Query XOR of nums[l..r] (inclusive, 0-indexed):
public int rangeXOR(int[] prefix, int l, int r) {
    return prefix[r + 1] ^ prefix[l]; // prefix[r+1] ^ prefix[l]
}`,
                javascript: `function buildPrefixXOR(nums) {
    let n = nums.length;
    int[] prefix = new Array(n + 1).fill(0); // prefix[0] = 0 (sentinel)
    for (let i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] ^ nums[i];
    }
    return prefix;
}

// Query XOR of nums[l..r] (inclusive, 0-indexed):
function rangeXOR(prefix, l, r) {
    return prefix[r + 1] ^ prefix[l]; // prefix[r+1] ^ prefix[l]
}`
              }
            }
          ]
        },
        {
          type: 'collapse',
          title: 'ii) Count Subarrays with XOR = k',
          tag: 'O(n) | HashMap of prefix XOR counts | Mirrors sum=k pattern',
          defaultOpen: false,
          blocks: [
            {
              type: 'p',
              text: 'Identical in shape to "count subarrays with sum = k" (Phase 2). For every prefix XOR value, store how many times it has appeared. At each index, check if `currentXOR ^ k` has been seen — if so, all subarrays ending here with XOR = k start from those positions.'
            },
            {
              type: 'p',
              text: '**Why `currentXOR ^ k`?** Because we want `prefix[r+1] ^ prefix[l] = k`, which means `prefix[l] = prefix[r+1] ^ k = currentXOR ^ k`.'
            },
            {
              type: 'code',
              language: 'java',
              label: 'Count Subarrays XOR = k (Java)',
              code: {
                java: `public int countSubarraysWithXOR(int[] nums, int k) {
    Map<Integer, Integer> prefixCount = new HashMap<>();
    prefixCount.put(0, 1); // sentinel: empty prefix XOR seen once
    int currentXOR = 0, count = 0;

    for (int num : nums) {
        currentXOR ^= num;
        // We want some previous prefix XOR = currentXOR ^ k
        count += prefixCount.getOrDefault(currentXOR ^ k, 0);
        prefixCount.merge(currentXOR, 1, Integer::sum);
    }
    return count;
}`,
                javascript: `function countSubarraysWithXOR(nums, k) {
    const prefixCount = new Map();
    prefixCount.set(0, 1); // sentinel: empty prefix XOR seen once
    let currentXOR = 0, count = 0;

    for (const num of nums) {
        currentXOR ^= num;
        // We want some previous prefix XOR = currentXOR ^ k
        count += (prefixCount[currentXOR ^ k] ?? 0);
        prefixCount.merge(currentXOR, 1, Integer::sum);
    }
    return count;
}`
              }
            }
          ]
        }
      ]
    },
    {
      num: '13',
      title: 'Related Patterns',
      blocks: [
        {
          type: 'chain',
          nodes: [
            { label: 'Prefix Sum (Phase 2)', desc: 'the direct structural parallel — same prefix trick, subtraction instead of XOR' },
            { label: 'Prefix XOR', desc: 'you are here', current: true },
            { label: 'XOR Pattern (Phase 12)', desc: 'the cancellation property that makes prefix XOR work' },
            { label: 'Bitwise Trie (Phase 11)', desc: 'combine with prefix XOR to find maximum XOR subarray' }
          ],
          arrows: [
            'XOR version of',
            'relies on',
            'extends to'
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
          id: 'prefix-xor-checklist',
          items: [
            'Am I using prefix[r+1] ^ prefix[l] (not prefix[r] ^ prefix[l-1])?',
            'Did I initialize prefix[0] = 0 as the sentinel?',
            'Counting subarrays with XOR = k: am I using HashMap with currentXOR ^ k as the lookup key?',
            'Maximum XOR subarray: did I consider combining Prefix XOR with a Bitwise Trie (Phase 11)?'
          ]
        }
      ]
    }
  ],
  conclusion: {
    title: '💡 Key takeaway',
    text: 'Prefix XOR is Prefix Sum\'s twin — same structural idea, XOR self-cancellation instead of arithmetic subtraction. The formula `prefix[r+1] ^ prefix[l]` gives any subarray\'s XOR in O(1). Master the off-by-one convention once and it never trips you again.'
  }
};

export default prefixXorBits;
