// Initial data and constants for Interview Prep Tracker

export const MOCK_INTERVIEW_QUESTIONS = [
  // Arrays & Strings
  {
    id: 1,
    category: 'Arrays & Strings',
    difficulty: 'Easy',
    question: 'What is the two-pointer technique and when would you use it?',
    answer: `The two-pointer technique uses two indices that traverse a data structure (usually an array or string) simultaneously, typically from opposite ends or at different speeds.\n\nUse cases:\n• Finding pairs that sum to a target in a sorted array\n• Reversing arrays/strings in-place\n• Detecting palindromes\n• Removing duplicates from sorted arrays\n• Sliding window problems\n\nTime complexity benefit: Reduces O(n²) brute force to O(n).`
  },
  {
    id: 2,
    category: 'Arrays & Strings',
    difficulty: 'Medium',
    question: 'Explain the sliding window technique with an example.',
    answer: `The sliding window technique maintains a "window" of elements in an array/string and slides it to find optimal subsets.\n\nExample - Maximum sum subarray of size k:\n\`\`\`\nfunction maxSumSubarray(arr, k) {\n  let maxSum = 0, windowSum = 0;\n  for (let i = 0; i < k; i++) windowSum += arr[i];\n  maxSum = windowSum;\n  for (let i = k; i < arr.length; i++) {\n    windowSum += arr[i] - arr[i - k];\n    maxSum = Math.max(maxSum, windowSum);\n  }\n  return maxSum;\n}\n\`\`\`\n\nTime: O(n), Space: O(1). Used for subarray/substring problems.`
  },
  {
    id: 3,
    category: 'Arrays & Strings',
    difficulty: 'Hard',
    question: 'How would you find the longest substring without repeating characters?',
    answer: `Use sliding window with a HashMap (character → last seen index).\n\nApproach:\n• Maintain left pointer and a map of char positions\n• For each right pointer char, if char exists in window, move left past it\n• Update map with current position\n• Track max window length\n\nTime: O(n), Space: O(min(n, charset_size))\n\nKey insight: The map tells us the last position of each character so we can jump the left pointer efficiently rather than moving one step at a time.`
  },
  // Linked Lists
  {
    id: 4,
    category: 'Linked Lists',
    difficulty: 'Easy',
    question: 'How do you detect a cycle in a linked list?',
    answer: `Floyd's Cycle Detection Algorithm (Tortoise and Hare):\n\n• Use two pointers: slow (1 step) and fast (2 steps)\n• If they meet → cycle exists\n• If fast reaches null → no cycle\n\nTime: O(n), Space: O(1)\n\nTo find cycle start:\n• After detection, reset slow to head\n• Move both pointers one step at a time\n• Where they meet is the cycle start\n\nThis works due to mathematical properties of modular arithmetic in the cycle.`
  },
  {
    id: 5,
    category: 'Linked Lists',
    difficulty: 'Medium',
    question: 'How would you reverse a linked list iteratively and recursively?',
    answer: `Iterative approach:\n\`\`\`\nlet prev = null, curr = head;\nwhile (curr) {\n  let next = curr.next;\n  curr.next = prev;\n  prev = curr;\n  curr = next;\n}\nreturn prev; // new head\n\`\`\`\n\nRecursive approach:\n\`\`\`\nfunction reverse(node) {\n  if (!node || !node.next) return node;\n  let newHead = reverse(node.next);\n  node.next.next = node;\n  node.next = null;\n  return newHead;\n}\n\`\`\`\n\nBoth: Time O(n), Space O(1) iterative / O(n) recursive (call stack).`
  },
  // Trees & Graphs
  {
    id: 6,
    category: 'Trees & Graphs',
    difficulty: 'Easy',
    question: 'What are the differences between BFS and DFS? When would you use each?',
    answer: `BFS (Breadth-First Search):\n• Explores level by level using a Queue\n• Finds shortest path in unweighted graphs\n• Uses more memory (stores all nodes at current level)\n• Best for: shortest path, level-order traversal, nearest neighbor\n\nDFS (Depth-First Search):\n• Explores as deep as possible using Stack/recursion\n• Better memory efficiency for deep/narrow trees\n• Best for: cycle detection, topological sort, maze solving, connected components\n\nTime: O(V+E) for both. Space: O(w) BFS (w=max width), O(h) DFS (h=height).`
  },
  {
    id: 7,
    category: 'Trees & Graphs',
    difficulty: 'Medium',
    question: 'Explain how to check if a binary tree is a valid BST.',
    answer: `Naive approach (checking left < root < right for each node) is WRONG because it doesn't account for all ancestors.\n\nCorrect approach - Pass valid range [min, max]:\n\`\`\`\nfunction isValid(node, min=-Infinity, max=Infinity) {\n  if (!node) return true;\n  if (node.val <= min || node.val >= max) return false;\n  return isValid(node.left, min, node.val) &&\n         isValid(node.right, node.val, max);\n}\n\`\`\`\n\nAlternatively: In-order traversal of a BST must produce a strictly increasing sequence.\n\nTime: O(n), Space: O(h) where h is tree height.`
  },
  {
    id: 8,
    category: 'Trees & Graphs',
    difficulty: 'Hard',
    question: 'How does Dijkstra\'s algorithm work and what are its limitations?',
    answer: `Dijkstra's finds the shortest path from a source to all vertices in a weighted graph.\n\nAlgorithm:\n1. Initialize distances: source=0, others=∞\n2. Use a min-heap (priority queue)\n3. Extract minimum distance vertex\n4. Relax all its neighbors: if dist[u] + weight(u,v) < dist[v], update\n5. Repeat until heap is empty\n\nTime: O((V+E) log V) with binary heap\nSpace: O(V)\n\nLimitations:\n• Does NOT work with negative edge weights\n• Use Bellman-Ford for negative weights\n• Use Floyd-Warshall for all-pairs shortest paths\n\nGreedy approach works because once a node is settled, the path is optimal.`
  },
  // Dynamic Programming
  {
    id: 9,
    category: 'Dynamic Programming',
    difficulty: 'Medium',
    question: 'What is memoization vs tabulation in dynamic programming?',
    answer: `Both are DP optimization techniques to avoid redundant computation.\n\nMemoization (Top-Down):\n• Recursive approach with caching\n• Only computes subproblems that are actually needed\n• More intuitive to write\n• Call stack overhead\n\`\`\`\nconst memo = {};\nfunction fib(n) {\n  if (n in memo) return memo[n];\n  if (n <= 1) return n;\n  return memo[n] = fib(n-1) + fib(n-2);\n}\n\`\`\`\n\nTabulation (Bottom-Up):\n• Iterative approach filling a table\n• Computes all subproblems\n• No recursion overhead, cache-friendly\n\`\`\`\nfunction fib(n) {\n  const dp = [0, 1];\n  for (let i=2; i<=n; i++) dp[i] = dp[i-1] + dp[i-2];\n  return dp[n];\n}\n\`\`\`\n\nTabulation often has better constants; memoization has simpler logic.`
  },
  {
    id: 10,
    category: 'Dynamic Programming',
    difficulty: 'Hard',
    question: 'Explain the 0/1 Knapsack problem and its DP solution.',
    answer: `Problem: Given items with weights and values, maximize value with a weight capacity W. Each item can only be used once.\n\nDP definition: dp[i][w] = max value using first i items with capacity w\n\nRecurrence:\n• If weight[i] > w: dp[i][w] = dp[i-1][w] (can't include item)\n• Else: dp[i][w] = max(dp[i-1][w], value[i] + dp[i-1][w-weight[i]])\n\nTime: O(n*W), Space: O(n*W) → optimized to O(W)\n\nSpace optimization - iterate w in reverse for 1D array:\n\`\`\`\nfor (let i=0; i<n; i++)\n  for (let w=W; w>=weight[i]; w--)\n    dp[w] = Math.max(dp[w], value[i] + dp[w-weight[i]]);\n\`\`\`\n\nKey insight: Reverse iteration prevents using same item twice.`
  },
  // System Design
  {
    id: 11,
    category: 'System Design',
    difficulty: 'Medium',
    question: 'What is the difference between horizontal and vertical scaling?',
    answer: `Vertical Scaling (Scale Up):\n• Add more resources (CPU, RAM) to existing server\n• Simpler - no distributed system complexity\n• Has hardware limits (ceiling)\n• Single point of failure\n• Examples: upgrading from t2.medium to t2.xlarge on AWS\n\nHorizontal Scaling (Scale Out):\n• Add more servers to distribute load\n• Theoretically unlimited scalability\n• Requires load balancing, distributed architecture\n• Better fault tolerance and availability\n• Examples: adding more EC2 instances, microservices\n\nModern systems prefer horizontal scaling for high availability. Stateless services scale horizontally easily; stateful services need careful design (sticky sessions, distributed caches).`
  },
  {
    id: 12,
    category: 'System Design',
    difficulty: 'Hard',
    question: 'How would you design a URL shortener like bit.ly?',
    answer: `Requirements: Shorten URLs, redirect, ~100M URLs/day, 10:1 read/write ratio\n\nKey Components:\n\n1. Unique ID Generation:\n   • Use base62 encoding (a-z, A-Z, 0-9) → 6 chars = 56B combinations\n   • Counter-based or random with collision check\n\n2. Database:\n   • SQL for strong consistency (key-value: short → long URL)\n   • Shard by hash of short URL\n\n3. Caching:\n   • Cache hot URLs in Redis (80/20 rule)\n   • TTL-based eviction\n\n4. API:\n   • POST /shorten → returns short URL\n   • GET /{code} → 301/302 redirect\n\n5. Load Balancer + CDN for global distribution\n\nWrite: 100M/day ≈ 1160/sec. Read: 11600/sec. Cache handles most reads.`
  },
  // OOP & Design Patterns
  {
    id: 13,
    category: 'OOP & Patterns',
    difficulty: 'Easy',
    question: 'Explain the SOLID principles with brief examples.',
    answer: `S - Single Responsibility: A class should have one reason to change. (UserAuth class handles auth only, not email sending)\n\nO - Open/Closed: Open for extension, closed for modification. (Add new shapes via inheritance, don't modify existing Shape class)\n\nL - Liskov Substitution: Subclasses must be substitutable for their parent class. (A Square should behave like a Rectangle in all contexts)\n\nI - Interface Segregation: No client should depend on methods it doesn't use. (Split fat interfaces into smaller, specific ones)\n\nD - Dependency Inversion: Depend on abstractions, not concretions. (Inject database interface, not specific MySQL class)\n\nFollowing SOLID leads to maintainable, extensible, testable code.`
  },
  {
    id: 14,
    category: 'OOP & Patterns',
    difficulty: 'Medium',
    question: 'What is the Observer pattern and where is it used?',
    answer: `Observer pattern defines a one-to-many dependency so when one object (Subject) changes state, all dependents (Observers) are notified automatically.\n\nComponents:\n• Subject (Observable): maintains list of observers, notifies them\n• Observer: interface with update() method\n• Concrete Observer: specific implementation\n\nReal-world examples:\n• Event listeners in JavaScript (addEventListener)\n• React's state/prop updates re-rendering components\n• Redux store subscriptions\n• News feed - subscriber gets notified of new articles\n• Stock ticker - investors notified of price changes\n• MVC pattern - View observes Model\n\nCode:\n\`\`\`\nclass EventEmitter {\n  constructor() { this.listeners = {}; }\n  on(event, fn) { (this.listeners[event]??=[]).push(fn); }\n  emit(event, data) { this.listeners[event]?.forEach(fn=>fn(data)); }\n}\n\`\`\``
  },
  // Recursion & Backtracking
  {
    id: 15,
    category: 'Recursion & Backtracking',
    difficulty: 'Medium',
    question: 'How does backtracking differ from brute force? Explain with N-Queens.',
    answer: `Brute force tries ALL combinations. Backtracking prunes invalid branches early, avoiding unnecessary computation.\n\nN-Queens: Place N queens on N×N board so none attack each other.\n\nBacktracking approach:\n1. Try placing queen in each column of current row\n2. Check if position is valid (no conflicts with placed queens)\n3. If valid: place queen, recurse to next row\n4. If recursion fails: remove queen (backtrack), try next column\n5. Base case: all rows filled → solution found\n\nPruning: Once a conflict is detected, we don't explore any children of that branch.\n\nTime: O(N!) worst case but practically much faster due to pruning.\n\nKey insight: "Build candidates incrementally and abandon (prune) a candidate as soon as it's determined it cannot lead to a valid solution."`
  },
  // Sorting & Searching
  {
    id: 16,
    category: 'Sorting & Searching',
    difficulty: 'Easy',
    question: 'Compare QuickSort vs MergeSort. When would you prefer one over the other?',
    answer: `QuickSort:\n• Avg: O(n log n), Worst: O(n²) - bad pivot selection\n• In-place: O(log n) space\n• Cache-friendly (good locality)\n• Not stable\n• Prefer for: in-memory sorting, when average case matters\n\nMergeSort:\n• Always O(n log n) - guaranteed\n• Requires O(n) extra space\n• Stable sort (preserves order of equal elements)\n• Better for: linked lists, external sorting, when stability required\n\nPractice: Most standard libraries use Timsort (hybrid) or Introsort (quicksort + heapsort fallback).\n\nRule of thumb: QuickSort for arrays in memory (faster in practice), MergeSort when stability or guaranteed performance needed.`
  },
];

export const CATEGORIES = ['All', 'Arrays & Strings', 'Linked Lists', 'Trees & Graphs', 'Dynamic Programming', 'System Design', 'OOP & Patterns', 'Recursion & Backtracking', 'Sorting & Searching'];

export const NOTE_COLORS = ['indigo', 'purple', 'cyan', 'green', 'yellow'];

export const PRIORITY_COLORS = {
  High: { bg: 'rgba(239,68,68,0.12)', color: '#ef4444' },
  Medium: { bg: 'rgba(245,158,11,0.12)', color: '#f59e0b' },
  Low: { bg: 'rgba(16,185,129,0.12)', color: '#10b981' },
};

export const INITIAL_GOALS = [
  { id: 1, text: 'Solve 3 LeetCode problems', priority: 'High', completed: false, createdAt: new Date().toISOString() },
  { id: 2, text: 'Review Binary Search concepts', priority: 'Medium', completed: false, createdAt: new Date().toISOString() },
  { id: 3, text: 'Watch 1 system design video', priority: 'Low', completed: true, createdAt: new Date().toISOString() },
];

export const INITIAL_NOTES = [
  {
    id: 1,
    title: 'Big-O Cheat Sheet',
    content: 'Array access: O(1)\nArray search: O(n)\nBST search: O(log n)\nHash map get/set: O(1) avg\nSorting: O(n log n)\nBFS/DFS: O(V+E)',
    color: 'indigo',
    createdAt: new Date().toISOString(),
  },
  {
    id: 2,
    title: 'Interview Tips',
    content: '1. Clarify the problem first\n2. Think out loud\n3. Start with brute force\n4. Optimize step-by-step\n5. Test with edge cases\n6. Discuss time & space complexity',
    color: 'green',
    createdAt: new Date().toISOString(),
  },
];

export const DSA_TOPICS = [
  'Arrays', 'Strings', 'Linked Lists', 'Stacks & Queues', 'Trees', 'Graphs',
  'Dynamic Programming', 'Recursion', 'Sorting', 'Binary Search', 'Hashing', 'Greedy'
];
