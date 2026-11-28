const segmentTree = {
  slug: 'segment-tree',
  phaseId: '16',
  eyebrow: 'Phase 16 — Range Structures',
  title: 'Segment Tree',
  lede: 'A binary tree built over an array where each node stores a precomputed aggregate (sum, min, max) over a contiguous range. Supports both range queries and point updates in O(log n) — a combination Prefix Sum fundamentally cannot offer. Lazy Propagation extends this to O(log n) range updates.',

  overview: [
    { label: 'Build', value: 'O(n) — each of ~2n nodes computed once' },
    { label: 'Query / Point Update', value: 'O(log n) each' },
    { label: 'Range Update (Lazy)', value: 'O(log n) — via deferred propagation' },
  ],

  sections: [
    {
      num: '01',
      title: 'What Is It?',
      blocks: [
        { type: 'p', text: 'A binary tree built directly **over** an array, where each node stores a precomputed aggregate (sum, min, max, etc.) over a contiguous range: leaves represent individual elements, and every internal node\'s value is the **combine** of its two children\'s ranges. Supports **both** range queries and point updates in O(log n) — a combination Prefix Sum (Phase 2) fundamentally cannot offer, since Prefix Sum trades O(1) query for O(n) update cost.' }
      ]
    },
    {
      num: '02',
      title: 'Why Do We Use It?',
      blocks: [
        { type: 'ul', items: [
          '**Problem it solves:** data that needs **both** frequent range queries **and** frequent updates, interleaved. Prefix Sum excels only when the array is static.',
          '**Why it works:** any arbitrary query range can be exactly decomposed into at most O(log n) precomputed canonical pieces — the tree\'s nodes. An update corrects only the O(log n) ancestors of one changed leaf.',
          '**Trade-off:** O(log n) for both operations, versus Prefix Sum\'s O(1) query / O(n) update, or plain array\'s O(n) query / O(1) update.'
        ] }
      ]
    },
    {
      num: '03',
      title: 'When Should I Think About Using It?',
      blocks: [
        { type: 'ul', items: [
          '"range sum query, array is **mutable**" — the "mutable" keyword is the tell',
          '"range minimum/maximum query"',
          '"range update, range query" (Lazy Propagation)'
        ] }
      ]
    },
    {
      num: '04',
      title: 'How Does It Work?',
      blocks: [
        { type: 'ul', items: [
          '**Build:** recursively split in half; leaf holds one element; internal node = combine(leftChild, rightChild).',
          '**Query(l,r):** if fully inside [l,r] → return precomputed value directly. If fully outside → return identity. If partial overlap → recurse both children and combine.',
          '**Update(idx, val):** walk to leaf, update it, recompute every ancestor on the way back up.'
        ] }
      ]
    },
    {
      num: '05',
      title: 'Dry Run — Range Sum with Point Update',
      blocks: [
        { type: 'p', text: '**Problem:** `arr = [1,3,5,7,9,11]`. Query `sum[1,4]` (expected `3+5+7+9=24`).' },
        { type: 'ascii', content: `                    root[0,5]=36
                   /            \\
            [0,2]=9            [3,5]=27
            /      \\            /      \\
       [0,1]=4   [2,2]=5   [3,4]=16  [5,5]=11
       /    \\
   [0,0]=1 [1,1]=3

Query[1,4]:
  root[0,5]: partial → recurse both
    left[0,2]: partial → recurse
      [0,1]: partial → leaf0(OUTSIDE→0); leaf1(INSIDE→3) = 3
      [2,2]: FULLY INSIDE [1,4] → return 5 directly
      left subtotal = 3+5 = 8
    right[3,5]: partial → recurse
      [3,4]: FULLY INSIDE [1,4] → return 16 directly
      [5,5]: FULLY OUTSIDE → return 0
      right subtotal = 16+0 = 16
  Total = 8+16 = 24 ✓  (only O(log n) nodes touched)` },
        { type: 'p', text: '**Point Update:** set index 2 from `5` to `10`.\n`tree[2,2] = 10` → recompute `tree[0,2] = 1+3+10 = 14` → recompute `root = 14+27 = 41`. Only the root-to-leaf path is touched.' }
      ]
    },
    {
      num: '10',
      title: 'The Catch ⭐',
      blocks: [
        { type: 'ul', items: [
          '**Size the array at `4n`, not `2n`** — non-power-of-2 input sizes cause out-of-bounds with `2n`. `4n` is the standard safe bound.',
          '**Fully-inside/fully-outside/partial decomposition boundary logic** — off-by-one on inclusive vs. exclusive range bounds silently returns wrong aggregates.',
          '**The "outside" identity value must match the combine operation:** `0` for sum, `+∞` for min, `-∞` for max. A stray `0` identity on a min tree would incorrectly become the minimum of everything.',
          '**When NOT to use it:** static array with no updates → plain Prefix Sum (Phase 2) is simpler, O(1) query, far less code.'
        ] }
      ]
    },
    {
      num: '12',
      title: 'Examples',
      blocks: [
        {
          type: 'collapse',
          title: 'i) Range Sum Query with Point Update',
          tag: 'O(n log n) build | O(log n) query/update',
          defaultOpen: true,
          blocks: [
            { type: 'code', language: 'java',
              label: 'Segment Tree — Sum (Java)',
              code: {
                java: `public class SegmentTree {
    int[] tree;
    int n;

    public SegmentTree(int[] arr) {
        n = arr.length;
        tree = new int[4 * n]; // 4n — safe for non-power-of-2
        build(arr, 0, 0, n - 1);
    }
    private void build(int[] arr, int node, int start, int end) {
        if (start == end) { tree[node] = arr[start]; return; }
        int mid = (start + end) / 2;
        build(arr, 2*node+1, start, mid);
        build(arr, 2*node+2, mid+1, end);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }

    public int query(int l, int r) { return query(0, 0, n-1, l, r); }
    private int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;              // fully outside — identity for sum
        if (l <= start && end <= r) return tree[node];    // fully inside — use precomputed
        int mid = (start + end) / 2;
        return query(2*node+1, start, mid, l, r) + query(2*node+2, mid+1, end, l, r);
    }

    public void update(int idx, int val) { update(0, 0, n-1, idx, val); }
    private void update(int node, int start, int end, int idx, int val) {
        if (start == end) { tree[node] = val; return; }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2*node+1, start, mid, idx, val);
        else            update(2*node+2, mid+1, end, idx, val);
        tree[node] = tree[2*node+1] + tree[2*node+2]; // recompute on the way back up
    }
}`,
                javascript: `class SegmentTree {
    int[] tree;
    

    constructor(int[] arr) {
        n = arr.length;
        tree = new Array(4 * n).fill(0); // 4n — safe for non-power-of-2
        build(arr, 0, 0, n - 1);
    }
    function build(arr, node, start, end) {
        if (start == end) { tree[node] = arr[start]; return; }
        let mid = (start + end) / 2;
        build(arr, 2*node+1, start, mid);
        build(arr, 2*node+2, mid+1, end);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }

    function query(l, r) { return query(0, 0, n-1, l, r); }
    function query(node, start, end, l, r) {
        if (r < start || end < l) return 0;              // fully outside — identity for sum
        if (l <= start && end <= r) return tree[node];    // fully inside — use precomputed
        let mid = (start + end) / 2;
        return query(2*node+1, start, mid, l, r) + query(2*node+2, mid+1, end, l, r);
    }

    function update(idx, val) { update(0, 0, n-1, idx, val); }
    function update(node, start, end, idx, val) {
        if (start == end) { tree[node] = val; return; }
        let mid = (start + end) / 2;
        if (idx <= mid) update(2*node+1, start, mid, idx, val);
        else            update(2*node+2, mid+1, end, idx, val);
        tree[node] = tree[2*node+1] + tree[2*node+2]; // recompute on the way back up
    }
}`
              } }
          ]
        },
        {
          type: 'collapse',
          title: 'ii) Range Minimum Query — same structure, different combine',
          tag: 'Identity = Integer.MAX_VALUE | Swap + for Math.min',
          defaultOpen: false,
          blocks: [
            { type: 'p', text: 'Identical tree mechanism, swapping `sum` for `min` — a direct illustration that Segment Tree is a **generic template** parametrized by any associative combine operation.' },
            { type: 'callout', variant: 'rose', title: 'Copy-paste bug: the identity value', text: 'The "outside" return value MUST match the operation. `0` works for sum — but for min it must be `Integer.MAX_VALUE` (so it never wins), and for max it must be `Integer.MIN_VALUE`. Keeping a sum-tree\'s `return 0` when adapting to min silently makes 0 the minimum of every range.' },
            { type: 'code', language: 'java',
              label: 'Range Minimum Query (Java)',
              code: {
                java: `// Same as SegmentTree above, with two changes:
// 1. tree[node] = Math.min(left, right)  in build() and update()
// 2. "fully outside" returns Integer.MAX_VALUE, not 0

private int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return Integer.MAX_VALUE; // identity for min
    if (l <= start && end <= r) return tree[node];
    int mid = (start + end) / 2;
    return Math.min(query(2*node+1, start, mid, l, r),
                    query(2*node+2, mid+1, end, l, r));
}`,
                javascript: `// Same as SegmentTree above, with two changes:
// 1. tree[node] = Math.min(left, right)  in build() and update()
// 2. "fully outside" returns Infinity, not 0

function query(node, start, end, l, r) {
    if (r < start || end < l) return Infinity; // identity for min
    if (l <= start && end <= r) return tree[node];
    let mid = (start + end) / 2;
    return Math.min(query(2*node+1, start, mid, l, r),
                    query(2*node+2, mid+1, end, l, r));
}`
              } }
          ]
        },
        {
          type: 'collapse',
          title: 'iii) Lazy Propagation — Range Update, Range Query',
          tag: 'O(log n) range update | Defer push-down until needed',
          defaultOpen: false,
          blocks: [
            { type: 'p', text: 'Extends Segment Tree to support **range** updates (e.g., "add V to every element in [l,r]") in O(log n). Naively updating each leaf individually is O(n log n) — defeating the purpose.\n\n**Mechanism:** when a node\'s range is fully covered by the update, apply directly to that node\'s aggregate and record a **pending lazy tag** — without touching children yet. When any future operation needs to descend past that node, **first push the tag down, then clear it, then recurse**.' },
            { type: 'p', text: '**Dry run:** `arr=[1,2,3,4,5,6]`, `rangeUpdate(0,2,+10)`:\n- `left[0,2]`: FULLY INSIDE → `sum += 10×3=30` → set `lazy[0,2]=+10` — children NOT touched.\n- `right[3,5]`: FULLY OUTSIDE → skip.\n- Root recomputed: `36+30=66`. Zero leaf-level work done, 2 nodes touched total.' },
            { type: 'callout', variant: 'rose', title: 'Two rules that cannot be broken', text: '1. **Push down BEFORE recursing into children** — reading/writing children with a stale pending tag corrupts results silently.\n\n2. **Clear the lazy tag immediately after pushing it down** — forgetting this reapplies the deferred update again on the next push, over-applying it.' },
            { type: 'code', language: 'java',
              label: 'Lazy Segment Tree (Java)',
              code: {
                java: `public class LazySegmentTree {
    long[] tree, lazy;
    int n;

    public LazySegmentTree(int[] arr) {
        n = arr.length;
        tree = new long[4 * n];
        lazy = new long[4 * n];
        build(arr, 0, 0, n - 1);
    }
    private void build(int[] arr, int node, int start, int end) {
        if (start == end) { tree[node] = arr[start]; return; }
        int mid = (start + end) / 2;
        build(arr, 2*node+1, start, mid);
        build(arr, 2*node+2, mid+1, end);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }

    private void pushDown(int node, int start, int end) {
        if (lazy[node] == 0) return;
        int mid = (start + end) / 2;
        int lc = 2*node+1, rc = 2*node+2;
        tree[lc] += lazy[node] * (mid - start + 1);  lazy[lc] += lazy[node];
        tree[rc] += lazy[node] * (end - mid);         lazy[rc] += lazy[node];
        lazy[node] = 0; // CLEAR after push — critical
    }

    public void rangeUpdate(int l, int r, int val) { rangeUpdate(0, 0, n-1, l, r, val); }
    private void rangeUpdate(int node, int start, int end, int l, int r, int val) {
        if (r < start || end < l) return;
        if (l <= start && end <= r) {
            tree[node] += (long) val * (end - start + 1);
            lazy[node] += val; // defer — do NOT recurse into children
            return;
        }
        pushDown(node, start, end); // MUST push before recursing
        int mid = (start + end) / 2;
        rangeUpdate(2*node+1, start, mid, l, r, val);
        rangeUpdate(2*node+2, mid+1, end, l, r, val);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }

    public long query(int l, int r) { return query(0, 0, n-1, l, r); }
    private long query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        pushDown(node, start, end); // MUST push before recursing
        int mid = (start + end) / 2;
        return query(2*node+1, start, mid, l, r) + query(2*node+2, mid+1, end, l, r);
    }
}`,
                javascript: `class LazySegmentTree {
    long[] tree, lazy;
    

    constructor(int[] arr) {
        n = arr.length;
        tree = new long[4 * n];
        lazy = new long[4 * n];
        build(arr, 0, 0, n - 1);
    }
    function build(arr, node, start, end) {
        if (start == end) { tree[node] = arr[start]; return; }
        let mid = (start + end) / 2;
        build(arr, 2*node+1, start, mid);
        build(arr, 2*node+2, mid+1, end);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }

    function pushDown(node, start, end) {
        if (lazy[node] == 0) return;
        let mid = (start + end) / 2;
        let lc = 2*node+1, rc = 2*node+2;
        tree[lc] += lazy[node] * (mid - start + 1);  lazy[lc] += lazy[node];
        tree[rc] += lazy[node] * (end - mid);         lazy[rc] += lazy[node];
        lazy[node] = 0; // CLEAR after push — critical
    }

    function rangeUpdate(l, r, val) { rangeUpdate(0, 0, n-1, l, r, val); }
    function rangeUpdate(node, start, end, l, r, val) {
        if (r < start || end < l) return;
        if (l <= start && end <= r) {
            tree[node] += (long) val * (end - start + 1);
            lazy[node] += val; // defer — do NOT recurse into children
            return;
        }
        pushDown(node, start, end); // MUST push before recursing
        let mid = (start + end) / 2;
        rangeUpdate(2*node+1, start, mid, l, r, val);
        rangeUpdate(2*node+2, mid+1, end, l, r, val);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }

    function query(l, r) { return query(0, 0, n-1, l, r); }
    function query(node, start, end, l, r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        pushDown(node, start, end); // MUST push before recursing
        let mid = (start + end) / 2;
        return query(2*node+1, start, mid, l, r) + query(2*node+2, mid+1, end, l, r);
    }
}`
              } }
          ]
        }
      ]
    },
    {
      num: '20',
      title: 'Interview Checklist',
      blocks: [
        { type: 'checklist', id: 'segment-tree-checklist', items: [
          'Does the array need BOTH range queries AND updates? Static-only → plain Prefix Sum instead.',
          'Is the tree array sized safely at 4n, not 2n?',
          'Is the fully-inside/fully-outside/partial boundary logic correct (inclusive vs. exclusive)?',
          'Does the "outside" identity match the operation (0 for sum, +∞/-∞ for min/max)?',
          'Lazy propagation: am I pushing down BEFORE recursing, and CLEARING the lazy tag after?',
          'Am I scaling the lazy update by range size (e.g., lazy * rangeLength for sum)?'
        ] }
      ]
    }
  ],
  conclusion: { title: '💡 Key takeaway', text: 'Segment Tree\'s insight: precompute O(n) canonical sub-range aggregates so any query range decomposes into O(log n) of them. Lazy Propagation further defers range-update work — if nothing asks to look inside, the work is simply never done.' }
};

export default segmentTree;
