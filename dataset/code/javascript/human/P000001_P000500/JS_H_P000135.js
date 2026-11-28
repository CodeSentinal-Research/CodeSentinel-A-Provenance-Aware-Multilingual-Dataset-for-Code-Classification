
const twoPointer = {
  slug: 'two-pointer',
  title: 'Two Pointer',
  phaseId: '01',
  eyebrow: 'phase 01 · array & hashing foundations',
  lede: 'Two Pointer is a technique where you use two index variables to scan through a data structure — usually an array or string — instead of one, moving them in a coordinated way to eliminate work a nested loop would repeat.',

  overview: [
    { label: 'Time (avg / worst)', value: 'O(n)' },
    { label: 'Space (auxiliary)', value: 'O(1)' },
    { label: 'Prerequisites', value: 'Loops, comparisons', small: true },
  ],

  sections: [
    {
      num: '01',
      title: 'What Is It?',
      blocks: [
        { type: 'p', text: 'Two Pointer is a technique where you use two index variables (pointers) to scan through a data structure — usually an array or string — instead of one. Rather than nested loops re-scanning the same data over and over, the two pointers move through the structure in a coordinated way, each carrying its own meaning (e.g., "the smallest unconfirmed value" and "the largest unconfirmed value").' },
        { type: 'p', text: 'Think of it like two people reading the same book from different starting points, occasionally meeting in the middle, each reporting what they see.' },
      ],
    },
    {
      num: '02',
      title: 'Why Do We Use It?',
      blocks: [
        {
          type: 'ul',
          items: [
            '**Problem it solves:** Many array problems ask "find a pair/subarray/partition satisfying some condition." The brute-force answer checks every pair — O(n²). Two Pointer often collapses this to O(n) by using structure in the data (usually sortedness or a monotonic relationship) to eliminate large chunks of the search space in one comparison.',
            '**Why it was invented:** It\'s an application of a simple observation — if data is sorted (or has a known monotonic property), moving a pointer in the "wrong direction" can never help, so you never need to backtrack. That guarantee is what lets you drop from quadratic to linear.',
            '**What makes it better than brute force:** Brute force re-examines information it already has. Two Pointer throws away information it has proven irrelevant and never looks at it again.',
          ],
        },
      ],
    },
    {
      num: '03',
      title: 'When Should I Think About Using It?',
      blocks: [
        { type: 'p', text: 'Common interview trigger phrases:' },
        {
          type: 'ul',
          items: [
            '"sorted array" + "find a pair/triplet with sum X"',
            '"in-place" modification with O(1) extra space',
            '"remove duplicates from sorted array"',
            '"container with most water" / "trapping rain water"',
            '"palindrome check"',
            '"merge two sorted arrays/lists"',
            '"partition array around a pivot" / "sort colors" / "Dutch national flag"',
            'Anything where brute force is O(n²) nested loops over one array and the array is sorted or can be meaningfully sorted',
          ],
        },
        {
          type: 'callout',
          variant: 'default',
          title: '💡 Pattern-recognition rule of thumb',
          text: 'If you find yourself writing a nested loop where the inner loop\'s useful range shrinks as the outer loop advances, that\'s a two-pointer smell.',
        },
      ],
    },
    {
      num: '04',
      title: 'How Does It Work?',
      blocks: [
        { type: 'p', text: 'There isn\'t one universal mechanism — it depends on the variation (see Section 12) — but the **opposite-ends** variant, the canonical one, works like this:' },
        {
          type: 'ol',
          items: [
            'Place one pointer (`left`) at the start, another (`right`) at the end.',
            'Evaluate the pair `(arr[left], arr[right])` against your target condition.',
            'Based on the result, move exactly one pointer inward: if the pair\'s value is too small, move `left` right; if too large, move `right` left; if it matches, record/return the answer.',
            'Stop when `left >= right`.',
          ],
        },
        { type: 'p', text: 'The reason step 3 is safe: because the array is sorted, moving the "wrong" pointer would only ever make the discrepancy worse, so the direction you pick is forced by the math, not a guess.' },
      ],
    },
    {
      num: '05',
      title: 'Dry Run',
      blocks: [
        { type: 'p', text: '**Problem:** Given a sorted array, find two numbers that sum to a target (Two Sum II style). Array: `[2, 7, 11, 15]`, Target: `9`' },
        {
          type: 'ascii',
          content: 'Index:   0   1   2   3\nValue:   2   7  11  15\n         ↑           ↑\n       left         right',
        },
        {
          type: 'table',
          headers: ['Step', 'left', 'right', 'arr[left]', 'arr[right]', 'sum', 'vs target', 'action'],
          rows: [
            ['1', '0', '3', '2', '15', '17', '17 > 9', 'sum too big → move right left'],
            ['2', '0', '2', '2', '11', '13', '13 > 9', 'sum too big → move right left'],
            ['3', '0', '1', '2', '7', '9', '9 == 9', '**match found!** return (0, 1)'],
          ],
        },
        {
          type: 'ascii',
          content: 'Final state:\nIndex:   0   1   2   3\nValue:   2   7  11  15\n         ↑   ↑\n       left right   → sum = 9 ✓',
        },
        { type: 'p', text: 'Total comparisons: 3 — versus 6 for brute force nested loops on this size, and the gap widens fast as n grows.' },
      ],
    },
    {
      num: '06',
      title: 'Visual Element Explanation',
      blocks: [
        { type: 'p', text: 'The mental model that generalizes across all two-pointer opposite-ends problems:' },
        {
          type: 'ascii',
          content: '[ smallest ......................... largest ]\n   ↑                                    ↑\n left                                 right\n\n   sum too small  → left++   (need a bigger contribution)\n   sum too big    → right--  (need a smaller contribution)\n   sum just right → record answer, then shrink the window',
        },
        { type: 'p', text: 'The "search space" is the region between `left` and `right`. Every step provably shrinks that region by at least one element, which is exactly why the algorithm terminates in O(n).' },
      ],
    },
    {
      num: '07',
      title: 'Time Complexity',
      blocks: [
        {
          type: 'complexity',
          items: [
            { label: 'Best case', value: 'O(1)' },
            { label: 'Average case', value: 'O(n)' },
            { label: 'Worst case', value: 'O(n)' },
          ],
        },
        {
          type: 'ul',
          items: [
            '**Best case — O(1):** the answer is found on the very first comparison (e.g., first and last element already match).',
            '**Average case — O(n):** pointers converge somewhere in the middle after examining a fraction of the array.',
            '**Worst case — O(n):** no match exists, or the match is found only when left and right meet; each pointer moves at most n times total across the whole run (never backward), so total work is bounded by n + n → O(n).',
          ],
        },
        { type: 'p', text: 'Why it\'s never worse than O(n): each iteration moves at least one pointer strictly inward, and there are only n positions to move through in total across both pointers combined — there is no scenario, given sorted input, where you re-visit a position.' },
      ],
    },
    {
      num: '08',
      title: 'Space Complexity',
      blocks: [
        {
          type: 'ul',
          items: [
            '**Auxiliary space — O(1):** only two integer index variables, no extra data structures.',
            '**Total space:** O(n) for the input array itself, already given and not allocated by the algorithm, plus O(1) auxiliary → effectively O(1) beyond input.',
          ],
        },
        { type: 'p', text: 'Why: unlike a hash-map based solution to the same problem, also O(n) time but O(n) *extra* space, two pointer exploits sortedness to avoid needing a lookup table at all.' },
      ],
    },
    {
      num: '09',
      title: 'Cost Analysis',
      blocks: [
        { type: 'p', text: 'Where the time actually goes:' },
        {
          type: 'ul',
          items: [
            '**Pointer movement:** the dominant cost — up to n total decrements/increments across both pointers.',
            '**Comparison per step:** O(1) — comparing two values and a target, constant work.',
            '**No nested loop, no recursion stack, no extra structure lookups** — this is why the technique is prized: the cost per unit of progress is as cheap as it gets, a single comparison, and progress is monotonic and never undone.',
          ],
        },
        { type: 'p', text: 'Contrast with brute force: nested loops cost O(n²) because the inner loop restarts from scratch for every outer iteration, re-examining information the two-pointer approach would have already ruled out.' },
      ],
    },
    {
      num: '10',
      title: 'The Catch ⭐',
      blocks: [
        {
          type: 'callout',
          variant: 'rose',
          title: '⚠ Sortedness assumption',
          text: 'Opposite-ends two pointer **requires** sorted (or sortable) input. If the array is unsorted and you can\'t sort it, e.g. you need to preserve original indices, you generally need a hash map instead — sorting costs O(n log n) and may destroy index information you need in the answer.',
        },
        {
          type: 'ul',
          items: [
            '**Off-by-one on the loop condition:** `while (left < right)` vs `while (left <= right)` — using `<=` on a pair-search can cause you to compare an element with itself, usually wrong for "two distinct elements" problems.',
            '**Duplicate handling:** for problems like 3Sum, after finding a valid pair/triplet you must skip over duplicate values on both pointers, or you\'ll return duplicate answers. Forgetting this is one of the most common interview mistakes on this pattern.',
            '**Infinite loops:** if you write a branch where neither pointer moves, a logic bug in the condition-to-action mapping, the loop never terminates. Always verify every branch of your if/else moves at least one pointer.',
            '**Overflow:** summing large integers can overflow 32-bit `int` in some languages — in Java, if values approach `Integer.MAX_VALUE`, cast to `long` for the sum comparison.',
            '**When NOT to use it:** unsorted data you cannot sort, problems needing all pairs/subsets rather than one optimal answer, or problems where the "monotonic" assumption doesn\'t actually hold — verify this before committing, since a wrong monotonicity assumption silently gives wrong answers, not a crash.',
          ],
        },
        {
          type: 'callout',
          variant: 'default',
          title: '🎯 Interview trap',
          text: 'Candidates often reach for two pointer out of habit on *any* pair-sum problem, without checking the array is sorted first. If it\'s not sorted and you can\'t afford O(n log n) sort, a hash map — O(n) time, O(n) space — is correct. Two pointer is not always strictly better.',
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
            'Array indexing and basic loop constructs.',
            'Comparison operators and conditional branching.',
            'Understanding of what "sorted" guarantees about neighboring elements.',
            'Basic Big-O intuition — comparing O(n²) vs O(n).',
          ],
        },
      ],
    },
    {
      num: '12',
      title: 'Variations',
      blocks: [
        {
          type: 'collapse',
          title: 'a) Opposite Ends (left + right converging)',
          tag: 'canonical',
          defaultOpen: true,
          blocks: [
            { type: 'p', text: 'Covered fully in Sections 4–6 above. Used for: pair-sum problems, palindrome checks, container with most water, reversing an array in place.' },
          ],
        },
        {
          type: 'collapse',
          title: 'b) Same Direction (fast & slow pointers)',
          tag: 'read / write',
          defaultOpen: false,
          blocks: [
            { type: 'p', text: 'Both pointers start at, or near, the same end and move forward, but at different rates or under different conditions — one "reads," one "writes."' },
            { type: 'p', text: '**Example:** Remove duplicates from sorted array `[1, 1, 2, 2, 3]`' },
            {
              type: 'ascii',
              content: 'slow (write position) →  writes the next unique value\nfast (read position)  →  scans ahead looking for the next new value\n\ni=0: slow=0 fast=0  arr=[1,1,2,2,3]  (slow marks last unique)\ni=1: fast=1  arr[fast]==arr[slow] → skip\ni=2: fast=2  arr[fast]!=arr[slow] → slow++, arr[slow]=arr[fast] → arr=[1,2,2,2,3], slow=1\ni=3: fast=3  arr[fast]==arr[slow] → skip\ni=4: fast=4  arr[fast]!=arr[slow] → slow++, arr[slow]=arr[fast] → arr=[1,2,3,2,3], slow=2\n\nResult: first slow+1 = 3 elements are the unique sorted values: [1,2,3]',
            },
            { type: 'p', text: "Used for: in-place deduplication, moving zeroes to the end, cycle detection in linked lists — Floyd's, covered in Phase 8." },
          ],
        },
        {
          type: 'collapse',
          title: 'c) Partition / Dutch National Flag',
          tag: '3 pointers',
          defaultOpen: false,
          blocks: [
            { type: 'p', text: 'Three pointers — `low`, `mid`, `high` — partition an array into three regions in a single pass, classically used to sort an array of 0s, 1s, and 2s without a full sort.' },
            { type: 'p', text: '**Goal:** `[2, 0, 2, 1, 1, 0]` → `[0,0,1,1,2,2]` (0s left, 1s middle, 2s right)' },
            {
              type: 'table',
              headers: ['step', 'low', 'mid', 'high', 'arr', 'action'],
              rows: [
                ['start', '0', '0', '5', '[2,0,2,1,1,0]', 'arr[mid]=2 → swap(mid,high), high--'],
                ['1', '0', '0', '4', '[0,0,2,1,1,2]', 'arr[mid]=0 → swap(low,mid), low++, mid++'],
                ['2', '1', '1', '4', '[0,0,2,1,1,2]', 'arr[mid]=0 → swap(low,mid), low++, mid++'],
                ['3', '2', '2', '4', '[0,0,2,1,1,2]', 'arr[mid]=2 → swap(mid,high), high--'],
                ['4', '2', '2', '3', '[0,0,1,1,2,2]', 'arr[mid]=1 → mid++'],
                ['5', '2', '3', '3', '[0,0,1,1,2,2]', 'arr[mid]=1 → mid++'],
                ['stop', '—', 'mid > high', '—', '[0,0,1,1,2,2]', 'done ✓'],
              ],
            },
            { type: 'p', text: "Used for: sorting with a fixed small set of distinct values in one pass, in-place partitioning — also the core idea behind Quickselect/Quicksort's partition step, previewing Phase 7." },
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
            { label: 'Two Pointer', desc: 'you are here', current: true },
            { label: 'Sliding Window', desc: 'phase 02' },
            { label: 'Prefix Sum', desc: 'phase 02' },
            { label: 'Binary Search on Answer', desc: 'phase 03' },
          ],
          arrows: [
            'when the region between pointers needs to track an aggregate — sum, count, distinct chars — instead of just two endpoint values',
            'when you need range-sum answers without re-scanning, instead of a moving window',
            'when the search space is monotonic but not literally array positions',
          ],
        },
        { type: 'p', text: '**When to choose which:** if you only care about two boundary elements and their relationship, use Two Pointer. If you care about everything inside a shrinking/growing window, use Sliding Window. If you need repeated range-sum queries, use Prefix Sum. If the search space is monotonic but not literally array positions, use Binary Search on Answer.' },
      ],
    },
    {
      num: '17',
      title: 'Intuition',
      blocks: [
        { type: 'p', text: "Imagine brute-forcing the pair-sum problem: you'd fix the smallest possible left value and try every right value, then move left forward and try every right value again — massive repeated work." },
        { type: 'p', text: 'The actual insight: if `arr[left] + arr[right]` is too big, then `right` is the problem — no value less than the current right helps for this specific left, because you\'d just be revisiting sums you already implicitly ruled out. The natural discovery path is: "I know the array is sorted → moving one pointer has a predictable, monotonic effect on the sum → so I never need to guess, the comparison itself tells me which pointer to move." That\'s the "aha" — sortedness converts search into a deterministic walk.' },
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
          code: `function twoPointerOppositeEnds(array, target):
    left = 0
    right = length(array) - 1

    while left < right:
        currentSum = array[left] + array[right]

        if currentSum == target:
            return (left, right)
        else if currentSum < target:
            left = left + 1
        else:
            right = right - 1

    return "no pair found"`,
        },
      ],
    },
    {
      num: '19',
      title: 'Code Template',
      titleSuffix: '— Java',
      blocks: [
        {
          type: 'code',
          language: 'java',
              label: 'variation a — opposite ends',
              code: {
                java: `public int[] twoSumSorted(int[] arr, int target) {
    int left = 0, right = arr.length - 1;
    while (left < right) {
        long sum = (long) arr[left] + arr[right]; // long guards against overflow
        if (sum == target) {
            return new int[]{left, right};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return new int[]{-1, -1}; // no pair found
}`,
                javascript: `function twoSumSorted(arr, target) {
    let left = 0, right = arr.length - 1;
    while (left < right) {
        let sum = (long) arr[left] + arr[right]; // long guards againstfunction if(target) {
            return new Array().fill(0){left, right};
        }function if(target) {
            left++;
        } else {
            right--;
        }
    }
    return new Array().fill(0){-1, -1}; // no pair found
}`
              },
        },
        {
          type: 'code',
          language: 'java',
              label: 'variation b — same direction (fast & slow) — remove duplicates in-place',
              code: {
                java: `public int removeDuplicates(int[] arr) {
    if (arr.length == 0) return 0;
    int slow = 0;
    for (int fast = 1; fast < arr.length; fast++) {
        if (arr[fast] != arr[slow]) {
            slow++;
            arr[slow] = arr[fast];
        }
    }
    return slow + 1; // new logical length
}`,
                javascript: `function removeDuplicates(arr) {
    if (arr.length == 0) return 0;
    let slow = 0;
    for (let fast = 1; fast < arr.length; fast++) {
        if (arr[fast] != arr[slow]) {
            slow++;
            arr[slow] = arr[fast];
        }
    }
    return slow + 1; // new logical length
}`
              },
        },
        {
          type: 'code',
          language: 'java',
              label: 'variation c — partition (Dutch National Flag)',
              code: {
                java: `public void sortColors(int[] arr) {
    int low = 0, mid = 0, high = arr.length - 1;
    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr, low++, mid++);
        } else if (arr[mid] == 1) {
            mid++;
        } else { // arr[mid] == 2
            swap(arr, mid, high--);
        }
    }
}

private void swap(int[] arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}`,
                javascript: `function sortColors(arr) {
    let low = 0, mid = 0, high = arr.length - 1;
    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr, low++, mid++);
        }function if(1) {
            mid++;
        } else { // arr[mid] == 2
            swap(arr, mid, high--);
        }
    }
}

function swap(arr, i, j) {
    let temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}`
              },
        },
      ],
    },
    {
      num: '20',
      title: 'Interview Checklist',
      blocks: [
        { type: 'p', text: 'Before reaching for Two Pointer, ask yourself — tap each to check it off:' },
        {
          type: 'checklist',
          id: 'tp-checklist',
          items: [
            'Is the array sorted, or can it be sorted without losing information I need, like original indices?',
            'Do I need exactly one optimal pair/partition, not all possible combinations?',
            "Can I afford O(1) extra space, or would a hash map's O(n) space actually be simpler/required — unsorted input, need original indices?",
            "Does moving one pointer have a predictable, monotonic effect on my target condition? If not, two pointer's core guarantee breaks.",
            'Do I need to modify the array in-place, or track a "read vs. write" position? Favor the same-direction variant.',
            'Am I partitioning around a pivot or a small fixed set of categories, like 0/1/2? Favor the partition variant.',
            'Have I planned duplicate-skipping logic if the problem involves distinct-value pairs/triplets?',
          ],
        },
      ],
    },
  ],

  conclusion: {
    variant: 'teal',
    title: '✓ Two Pointer — fully documented',
    text: 'Next up in Phase 1: **Hash Map** — Frequency Based, Lookup Based, Set Based, Index Mapping, Grouping Pattern. Follow the steps in the roadmap\'s "How This Tracker Grows" section to slot it in.',
  },
};

export default twoPointer;
