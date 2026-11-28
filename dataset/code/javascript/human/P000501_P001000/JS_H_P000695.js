const binarySearchIndex = {
  slug: 'binary-search-index',
  phaseId: '03',
  eyebrow: 'Phase 3 — Binary Search',
  title: 'Binary Search on Index',
  lede:
    'Binary Search on Index is a search technique that repeatedly halves a sorted search space — instead of checking every candidate linearly, you check the midpoint and use the comparison result to discard the entire irrelevant half in one step, achieving O(log n) where brute force costs O(n).',

  overview: [
    { label: 'Time Complexity', value: 'O(log n)' },
    { label: 'Space Complexity', value: 'O(1) iterative · O(log n) recursive' },
    { label: 'Prerequisites', value: 'Sorted-array reasoning, comparison operators, basic loop/recursion' },
  ],

  sections: [
    {
      num: '01',
      title: 'What Is It?',
      blocks: [
        {
          type: 'p',
          text: 'Binary Search is a search technique that repeatedly halves a search space by exploiting a **monotonic** (sorted, or "feasible/infeasible") property. Instead of checking every candidate one by one, you check the middle candidate and use the result to eliminate half the remaining possibilities in one comparison.',
        },
        {
          type: 'p',
          text: 'Think of it like looking up a word in a dictionary: you open to the middle, decide which half the word is in, and throw away the other half — repeating until you land on the word.',
        },
      ],
    },
    {
      num: '02',
      title: 'Why Do We Use It?',
      blocks: [
        {
          type: 'ul',
          items: [
            '**Problem it solves:** finding a target (or a boundary) in a search space where linear scanning is wasteful because the space has a known order.',
            '**Why it was invented:** if you know everything left of some point is "too small" and everything right is "too big," checking the midpoint tells you which entire half to discard — you never need to look at the discarded half again.',
            '**What makes it better than brute force:** O(log n) instead of O(n) — for a million elements, that\'s ~20 comparisons instead of up to a million.',
          ],
        },
      ],
    },
    {
      num: '03',
      title: 'When Should I Think About Using It?',
      blocks: [
        {
          type: 'p',
          text: 'Common interview trigger phrases:',
        },
        {
          type: 'ul',
          items: [
            '"sorted array" + "find target/position"',
            '"find first/last occurrence"',
            '"minimize the maximum X such that condition Y holds" / "maximize the minimum X such that..."',
            '"smallest/largest value satisfying a condition" where checking one candidate is easy but the answer itself isn\'t obvious',
            'Any O(n) or O(n log n) brute force where the answer space is provably monotonic',
          ],
        },
      ],
    },
    {
      num: '04',
      title: 'How Does It Work?',
      blocks: [
        {
          type: 'ol',
          items: [
            'Maintain `lo` and `hi` boundaries of the search space.',
            'Compute `mid = lo + (hi - lo) / 2` (roughly the midpoint).',
            'Evaluate the condition at `mid`.',
            'Based on the result, discard the half that can\'t contain the answer — move `lo` or `hi` accordingly.',
            'Repeat until the space collapses to the answer.',
          ],
        },
      ],
    },
    {
      num: '05',
      title: 'Dry Run',
      titleSuffix: 'arr = [1, 3, 5, 7, 9, 11], target = 7',
      blocks: [
        {
          type: 'table',
          headers: ['lo', 'hi', 'mid', 'arr[mid]', 'vs target', 'action'],
          rows: [
            ['0', '5', '2', '5', '5 < 7', 'lo = mid + 1 = 3'],
            ['3', '5', '4', '9', '9 > 7', 'hi = mid - 1 = 3'],
            ['3', '3', '3', '7', 'match ✓', 'return index 3'],
          ],
        },
        {
          type: 'p',
          text: 'Answer: **index 3**. Three comparisons on an array of 6 — versus up to 6 for a linear scan.',
        },
      ],
    },
    {
      num: '06',
      title: 'Visual Element Explanation',
      blocks: [
        {
          type: 'ascii',
          content: `[1, 3, 5, 7, 9, 11]
 └──────┬──────┘
       mid=5 → too small → discard left half
              [7, 9, 11]
                └─┬─┘
               mid=9 → too big → discard right half
                [7]  ← found`,
        },
        {
          type: 'p',
          text: 'Each step the search space is provably cut in half. The algorithm can only run for as many steps as you can halve n before reaching 1 — which is exactly log₂(n).',
        },
      ],
    },
    {
      num: '07',
      title: 'Time Complexity',
      blocks: [
        {
          type: 'complexity',
          items: [
            { label: 'Best case', value: 'O(1) — target is the first mid checked' },
            { label: 'Average case', value: 'O(log n)' },
            { label: 'Worst case', value: 'O(log n) — target not present, space fully exhausted' },
          ],
        },
        {
          type: 'p',
          text: 'Each step halves the remaining space. Starting from n, you can halve at most log₂(n) times before reaching 1. That is the ceiling on how many comparisons you ever make.',
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
            '**Iterative — O(1):** only `lo`, `hi`, `mid` variables. No extra memory regardless of n.',
            '**Recursive — O(log n):** each recursive call adds one frame to the call stack, and the maximum recursion depth matches the number of halvings = log₂(n).',
          ],
        },
      ],
    },
    {
      num: '09',
      title: 'Cost Analysis',
      blocks: [
        {
          type: 'p',
          text: 'Each step costs O(1) — one midpoint calculation plus one comparison. Total steps ≈ log₂(n). The cost is entirely in the **number of halvings**, not in any per-step scanning.',
        },
        {
          type: 'p',
          text: 'Contrast with linear search: every element is a potential comparison. Binary search never revisits a discarded half — that is what makes the logarithmic bound tight.',
        },
      ],
    },
    {
      num: '10',
      title: 'The Catch ⭐',
      titleSuffix: 'What to watch out for',
      blocks: [
        {
          type: 'callout',
          variant: 'rose',
          title: '⚠ Integer overflow on mid',
          text: '`mid = (lo + hi) / 2` can overflow for large lo and hi in some languages. Always use `lo + (hi - lo) / 2` instead. Less of a concern in Java for typical array sizes, but a worth building as a habit now.',
        },
        {
          type: 'ul',
          items: [
            '**`lo <= hi` vs `lo < hi`:** mixing loop-termination conventions with boundary-update conventions (`hi = mid - 1` vs `hi = mid`) is the #1 source of infinite loops or off-by-one misses. Classic search uses `lo <= hi` + `hi = mid - 1`.',
            '**Duplicate values:** plain binary search finds *a* match, not necessarily the first or last. Leftmost/rightmost boundary search needs a different update rule — on a match, keep narrowing toward the boundary instead of stopping.',
            '**When NOT to use it:** unsorted data with no monotonic property to exploit — binary search will silently give wrong answers, not a crash.',
          ],
        },
        {
          type: 'callout',
          variant: 'default',
          title: '💡 Leftmost / Rightmost variants',
          text: 'For leftmost occurrence: on a match set `hi = mid` and continue. For rightmost: on a match set `lo = mid + 1` and continue, then check `lo - 1` at the end. This handles duplicates correctly without breaking the convergence guarantee.',
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
            'Sorted-array reasoning — knowing what "sorted" guarantees about element relationships.',
            'Comparison operators and conditional branching.',
            'Basic loop or recursion mechanics.',
            'Big-O intuition — recognizing why O(log n) beats O(n) and how halving produces logarithmic depth.',
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
          text: 'The classic index form splits into three variants based on what you\'re looking for:',
        },
        {
          type: 'collapse',
          title: 'a) Exact Value Search',
          tag: 'canonical',
          defaultOpen: true,
          blocks: [
            {
              type: 'p',
              text: 'Covered fully in Sections 4–6 above. Stop immediately on a match. Returns the index of the target or -1.',
            },
          ],
        },
        {
          type: 'collapse',
          title: 'b) Leftmost Occurrence',
          tag: 'boundary',
          defaultOpen: false,
          blocks: [
            {
              type: 'p',
              text: 'When duplicates exist and you need the **first** index of the target: on a match, do not return — instead set `hi = mid` and continue narrowing left.',
            },
            {
              type: 'ascii',
              content: `arr = [1, 3, 3, 3, 7]  target = 3

lo=0, hi=4  mid=2  arr[2]=3 → match, but keep going: hi=2
lo=0, hi=2  mid=1  arr[1]=3 → match, hi=1
lo=0, hi=1  mid=0  arr[0]=1 → too small: lo=1
lo=1, hi=1  → loop ends (lo == hi)
return lo = 1  ← first index of 3`,
            },
          ],
        },
        {
          type: 'collapse',
          title: 'c) Rightmost Occurrence',
          tag: 'boundary',
          defaultOpen: false,
          blocks: [
            {
              type: 'p',
              text: 'When you need the **last** index of the target: on a match set `lo = mid + 1` and continue narrowing right. After the loop, check `lo - 1`.',
            },
            {
              type: 'ascii',
              content: `arr = [1, 3, 3, 3, 7]  target = 3

lo=0, hi=4  mid=2  arr[2]=3 → match: lo=3
lo=3, hi=4  mid=3  arr[3]=3 → match: lo=4
lo=4, hi=4  → loop ends
return lo-1 = 3  ← last index of 3`,
            },
          ],
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
            { label: 'Binary Search on Index', desc: 'you are here — searching literal array positions', current: true },
            { label: 'Binary Search on Answer', desc: 'phase 03 — same halving idea over an abstract answer range' },
            { label: 'Two Pointer', desc: 'phase 01 — both narrow a search space, but moves both boundaries based on comparisons, not a single midpoint' },
            { label: 'Sliding Window', desc: 'phase 02 — contrast: scans linearly through a window rather than jumping to midpoints' },
          ],
          arrows: [
            'when search space is not literal array indices but a range of candidate answers',
            'when you need to narrow both ends simultaneously using element values',
            'when the scan must cover every element in a contiguous region',
          ],
        },
        {
          type: 'p',
          text: '**When to choose which:** searching for a value\'s position in sorted data → Binary Search on Index. Searching for an optimal threshold where checking one candidate is easy but the threshold itself is not obvious → Binary Search on Answer.',
        },
      ],
    },
    {
      num: '17',
      title: 'Intuition',
      blocks: [
        {
          type: 'p',
          text: 'If you know the array is sorted, checking the midpoint tells you definitively which half the target **cannot** be in — discard it, repeat. The key insight is that a single O(1) comparison eliminates half the remaining work. No matter how large the array is, you can only halve it log₂(n) times before you run out of elements to halve.',
        },
        {
          type: 'p',
          text: 'Binary Search on Answer is the same idea one level of abstraction up: instead of "is my target bigger or smaller than this array element," you ask "does this candidate answer work or not" — and if the answer to that question flips exactly once as the candidate increases (monotonicity), you can hunt for that flip point the same way.',
        },
      ],
    },
    {
      num: '18',
      title: 'Pseudocode',
      blocks: [
        {
          type: 'code',
          language: 'plaintext',
          label: 'pseudocode',
          code: `function binarySearch(array, target):
    lo = 0
    hi = length(array) - 1

    while lo <= hi:
        mid = lo + (hi - lo) / 2
        if array[mid] == target:
            return mid
        else if array[mid] < target:
            lo = mid + 1
        else:
            hi = mid - 1

    return -1  // not found`,
        },
      ],
    },
    {
      num: '19',
      title: 'Code Templates',
      titleSuffix: '— Java',
      blocks: [
        {
          type: 'code',
          language: 'java',
              label: 'Iterative — exact value search',
              code: {
                java: `public int binarySearch(int[] arr, int target) {
    int lo = 0, hi = arr.length - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}`,
                javascript: `function binarySearch(arr, target) {
    let lo = 0, hi = arr.length - 1;
    while (lo <= hi) {
        let mid = lo + (hi - lo) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}`
              },
        },
        {
          type: 'code',
          language: 'java',
              label: 'Recursive — exact value search',
              code: {
                java: `public int binarySearchRecursive(int[] arr, int target, int lo, int hi) {
    if (lo > hi) return -1;
    int mid = lo + (hi - lo) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) return binarySearchRecursive(arr, target, mid + 1, hi);
    else return binarySearchRecursive(arr, target, lo, mid - 1);
}`,
                javascript: `function binarySearchRecursive(arr, target, lo, hi) {
    if (lo > hi) return -1;
    let mid = lo + (hi - lo) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) return binarySearchRecursive(arr, target, mid + 1, hi);
    else return binarySearchRecursive(arr, target, lo, mid - 1);
}`
              },
        },
        {
          type: 'code',
          language: 'java',
              label: 'Leftmost occurrence (first index of target)',
              code: {
                java: `public int leftmostBinarySearch(int[] arr, int target) {
    int lo = 0, hi = arr.length - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] < target) lo = mid + 1;
        else hi = mid; // arr[mid] >= target: mid could be the answer, keep it in range
    }
    return (arr[lo] == target) ? lo : -1;
}`,
                javascript: `function leftmostBinarySearch(arr, target) {
    let lo = 0, hi = arr.length - 1;
    while (lo < hi) {
        let mid = lo + (hi - lo) / 2;
        if (arr[mid] < target) lo = mid + 1;
        else hi = mid; // arr[mid] >= target: mid could be the answer, keep it in range
    }
    return (arr[lo] == target) ? lo : -1;
}`
              },
        },
        {
          type: 'code',
          language: 'java',
              label: 'Rightmost occurrence (last index of target)',
              code: {
                java: `public int rightmostBinarySearch(int[] arr, int target) {
    int lo = 0, hi = arr.length - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2; // upper-mid to avoid infinite loop when lo+1==hi
        if (arr[mid] > target) hi = mid - 1;
        else lo = mid; // arr[mid] <= target: mid could be the answer
    }
    return (arr[lo] == target) ? lo : -1;
}`,
                javascript: `function rightmostBinarySearch(arr, target) {
    let lo = 0, hi = arr.length - 1;
    while (lo < hi) {
        let mid = lo + (hi - lo + 1) / 2; // upper-mid to avoid infinite loop when lo+1==hi
        if (arr[mid] > target) hi = mid - 1;
        else lo = mid; // arr[mid] <= target: mid could be the answer
    }
    return (arr[lo] == target) ? lo : -1;
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
          id: 'bsi-checklist',
          items: [
            'Is the data sorted, or is there a genuine monotonic property I can exploit?',
            'Am I searching for a literal value\'s position, or for a threshold in an abstract answer space? (If threshold → Binary Search on Answer.)',
            'Which loop/update convention am I using — `lo <= hi` with `hi = mid - 1`, or `lo < hi` with `hi = mid`? Pick one and be consistent.',
            'Do I have duplicates, and do I need the first or last occurrence specifically? (If yes → leftmost/rightmost variant.)',
            'Could my `mid` calculation overflow on large lo + hi? (Use `lo + (hi - lo) / 2`.)',
            'Have I confirmed what to return when the target is NOT found — `-1`, `lo`, or `lo - 1` depending on the variant?',
          ],
        },
      ],
    },
  ],

  conclusion: {
    title: '💡 Key Takeaway',
    text: 'Binary Search on Index achieves O(log n) by exploiting sorted order: one comparison at the midpoint eliminates half the remaining space forever. Use `lo + (hi - lo) / 2` to avoid overflow. For duplicates, use the leftmost/rightmost variant — never stop at the first match. Next: **Binary Search on Answer** — the same halving idea applied to an abstract range of candidate answers.',
  },
};

export default binarySearchIndex;
