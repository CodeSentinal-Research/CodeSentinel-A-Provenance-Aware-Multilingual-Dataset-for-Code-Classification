// Striver's A2Z DSA Course — Complete 316 video structure
// Format: [stepId, stepTitle, [[subtopicId, subtopicTitle, [videoTitles...]]...]]

const RAW = [
  [1, "Learn the Basics", [
    ["1.1", "Basic C++/Java/Python Setup", [
      "User Input/Output", "Data Types, Variables, Operators",
      "Conditionals (if/else, switch)", "Loops (for, while, do-while)", "Functions & Scope"
    ]],
    ["1.2", "Patterns", [
      "Star Patterns (right triangle, pyramid, diamond)", "Number Patterns (part 1)",
      "Number Patterns (part 2)", "Hollow Patterns (part 1)", "Hollow Patterns (part 2)",
      "Mixed Pattern Problems"
    ]],
    ["1.3", "C++ STL / Java Collections", [
      "Pairs, Vectors/ArrayLists", "Maps, Sets, Stacks, Queues",
      "Priority Queue, Multiset", "STL Practice Problems"
    ]],
    ["1.4", "Basic Mathematics", [
      "Count digits in a number", "Reverse a number", "Check Palindrome",
      "GCD / Euclidean Algorithm", "Armstrong Numbers", "Print all divisors",
      "Check prime number"
    ]],
    ["1.5", "Basic Recursion", [
      "Introduction to Recursion", "Print 1 to N, N to 1 using Recursion",
      "Factorial & Fibonacci via Recursion", "Reverse an Array using Recursion",
      "Check palindrome using Recursion"
    ]],
    ["1.6", "Basic Hashing", [
      "Introduction to Hashing", "Frequency count using arrays",
      "Hashing using maps", "Collision handling concepts"
    ]]
  ]],
  [2, "Sorting Techniques", [
    ["2.1", "Sorting-I", [
      "Selection Sort", "Bubble Sort", "Insertion Sort"
    ]],
    ["2.2", "Sorting-II", [
      "Merge Sort", "Recursive Bubble Sort", "Recursive Insertion Sort", "Quick Sort"
    ]]
  ]],
  [3, "Arrays", [
    ["3.1", "Easy Arrays", [
      "Largest element in array", "Second largest (without sorting)",
      "Check sorted array", "Remove duplicates from sorted array",
      "Left rotate array by one place", "Left rotate array by D places",
      "Move zeros to end", "Linear search", "Union of two sorted arrays",
      "Find missing number", "Count max consecutive 1s",
      "Find number appearing once", "Longest subarray with given sum (positives)",
      "Longest subarray with given sum (positives + zeros)",
      "Two sum problem", "Sort array of 0s, 1s, 2s"
    ]],
    ["3.2", "Medium Arrays", [
      "2-sum problem (all approaches)", "3-sum problem",
      "Majority element (>n/2 times)", "Majority element (>n/3 times)",
      "Maximum subarray sum (Kadane's Algorithm)", "Maximum product subarray",
      "Stock buy and sell (single transaction)", "Rotate matrix by 90 degrees",
      "Set matrix zeros", "Spiral traversal of matrix",
      "Count subarrays with given XOR", "Merge overlapping intervals",
      "Merge two sorted arrays without extra space",
      "Find duplicate in array (Floyd's cycle)"
    ]],
    ["3.3", "Hard Arrays", [
      "Pascal's Triangle", "Reverse pairs (Merge Sort based)",
      "Maximum sum rectangle in matrix", "4-sum problem",
      "Longest consecutive sequence", "Count inversions in array",
      "Count subarrays with sum K (prefix sum)", "Largest rectangle in histogram",
      "Subarray with given XOR", "Merge K sorted arrays"
    ]]
  ]],
  [4, "Binary Search", [
    ["4.1", "BS on 1D Arrays", [
      "Binary Search introduction", "Lower bound & upper bound",
      "Search insert position", "Floor & ceiling in sorted array",
      "First and last occurrence", "Count occurrences in sorted array",
      "Search in rotated sorted array (unique)",
      "Search in rotated sorted array (duplicates)",
      "Find minimum in rotated sorted array",
      "Find out how many times array is rotated",
      "Single element in sorted array", "Find peak element"
    ]],
    ["4.2", "BS on Answers", [
      "Find square root using BS", "Find Nth root of a number",
      "Koko eating bananas", "Minimum days to make M bouquets",
      "Find smallest divisor", "Capacity to ship packages in D days",
      "Kth missing positive number", "Aggressive cows (SPOJ)",
      "Book allocation problem", "Split array — largest sum",
      "Minimize max distance to gas stations", "Painter's partition problem"
    ]],
    ["4.3", "BS on 2D Arrays", [
      "Find the row with max 1s", "Search in a 2D matrix (Leetcode 74)",
      "Search in a 2D matrix II (Leetcode 240)",
      "Find peak element in 2D matrix", "Median of row-wise sorted matrix"
    ]]
  ]],
  [5, "Strings", [
    ["5.1", "Basic String Problems", [
      "Remove outermost parentheses", "Reverse words in a string",
      "Largest odd number in string", "Longest common prefix",
      "Isomorphic strings", "Check if string is rotation of another",
      "Check if two strings are anagrams"
    ]],
    ["5.2", "Medium String Problems", [
      "Sort characters by frequency", "Maximum nesting depth of parentheses",
      "Roman to Integer", "Integer to Roman", "Implement atoi",
      "Count number of substrings", "Longest palindromic substring",
      "Sum of beauty of all substrings"
    ]]
  ]],
  [6, "Linked List", [
    ["6.1", "Learn 1D LinkedList", [
      "Introduction to LinkedList", "Inserting a node in LinkedList",
      "Deleting a node in LinkedList", "Find length of LinkedList",
      "Search an element in LL"
    ]],
    ["6.2", "Learn Doubly LinkedList", [
      "Introduction to Doubly LinkedList", "Insert at front/tail/position",
      "Delete head/tail/position", "Reverse a Doubly LinkedList"
    ]],
    ["6.3", "Medium Problems of LL", [
      "Middle of LinkedList", "Detect a loop/cycle in LL",
      "Find length of loop", "Check if LL is palindrome",
      "Segregate odd/even nodes", "Remove Nth node from back",
      "Delete the middle node", "Sort LinkedList (Merge Sort)",
      "Sort a LL of 0s, 1s, 2s", "Find intersection of two LLs",
      "Add 1 to number represented as LL", "Add two numbers as LL",
      "Odd-Even LinkedList", "Reverse a LL in groups of K", "Rotate a LL"
    ]],
    ["6.4", "Medium Problems of DLL", [
      "Delete all occurrences of a key", "Find pairs with given sum in DLL",
      "Remove duplicates from sorted DLL"
    ]],
    ["6.5", "Hard Problems of LL", [
      "Reverse LL in group of given size K", "Flattening of LL",
      "Clone a linked list with random pointer",
      "Find starting point of loop in LL"
    ]]
  ]],
  [7, "Recursion & Backtracking", [
    ["7.1", "Get a strong hold on Recursion", [
      "Recursive implementation of atoi", "Pow(x, n)", "Count good numbers",
      "Sort a stack using recursion", "Reverse a stack using recursion",
      "Print all subsequences / Power Set"
    ]],
    ["7.2", "Subsequences Pattern", [
      "Generate all subsequences", "Subsequence with sum K (print all)",
      "Subsequence with sum K (count)", "Check if any subsequence with sum K exists",
      "Combination Sum II"
    ]],
    ["7.3", "Trying out all combos / Hard", [
      "Combination Sum I", "Subset Sum I", "Subset Sum II (no duplicates)",
      "Permutation sequence", "Permutations (all)", "N-Queens problem",
      "Sudoku Solver", "Word Search", "Rat in a Maze", "Word Break",
      "M-Coloring Problem", "Palindrome Partitioning",
      "K-th Permutation Sequence", "Expression Add Operators"
    ]]
  ]],
  [8, "Bit Manipulation", [
    ["8.1", "Concept Overview", [
      "Introduction to bit manipulation", "Check ith bit set or not",
      "Set / clear / toggle ith bit", "Remove last set bit",
      "Check if number is a power of 2", "Count the number of set bits"
    ]],
    ["8.2", "Interview Problems", [
      "Find XOR of numbers from L to R", "Find the two numbers appearing odd times",
      "Power Set using bits", "Find XOR of all numbers 1 to N",
      "Divide two integers without * or /", "All subsets using bit manipulation",
      "Minimum Bit Flips to convert number"
    ]],
    ["8.3", "Advanced Maths", [
      "Print prime factors", "All divisors of a number",
      "Sieve of Eratosthenes", "Find prime factorisation using sieve",
      "Modular Exponentiation"
    ]]
  ]],
  [9, "Stack & Queue", [
    ["9.1", "Learn Stack & Queue", [
      "Implement Stack using Arrays", "Implement Queue using Arrays",
      "Implement Stack using Queue", "Implement Queue using Stack",
      "Implement Stack using LinkedList", "Implement Queue using LinkedList"
    ]],
    ["9.2", "Prefix, Infix, PostFix Conversion", [
      "Infix to Postfix conversion", "Prefix to Infix conversion",
      "Prefix to Postfix conversion", "Postfix to Prefix conversion",
      "Postfix to Infix conversion"
    ]],
    ["9.3", "Monotonic Stack / Queue", [
      "Next greater element I & II", "Previous greater element",
      "Next smaller element", "Previous smaller element",
      "Number of NGE to the right", "Trapping rainwater",
      "Sum of subarray minimums", "Asteroid collision",
      "Sum of subarray ranges", "Remove k digits",
      "Largest rectangle in histogram", "Maximal rectangle in matrix",
      "Sliding window maximum", "Online stock span"
    ]],
    ["9.4", "Implementation Problems", [
      "Implement Min Stack", "Rotting oranges (BFS-based)",
      "Stock span problem", "Maximum of minimum for every window size",
      "The Celebrity problem"
    ]]
  ]],
  [10, "Sliding Window & Two Pointer", [
    ["10.1", "Medium Problems", [
      "Maximum points from cards",
      "Maximum consecutive 1s after flipping K zeros",
      "Longest subarray with at most K distinct integers",
      "Fruit into baskets", "Longest substring without repeating characters",
      "Number of substrings with all 3 characters"
    ]],
    ["10.2", "Hard Problems", [
      "Count of substrings with at most K distinct chars",
      "Binary subarrays with sum", "Count number of nice subarrays",
      "Subarrays with K different integers", "Minimum window substring",
      "Minimum window containing subsequence"
    ]]
  ]],
  [11, "Heaps", [
    ["11.1", "Learn Heaps", [
      "Introduction to Heaps", "Min Heap vs Max Heap",
      "Implement Min Heap from scratch", "Heapify and Heap Sort"
    ]],
    ["11.2", "Medium Problems", [
      "Kth largest element in array", "Kth smallest element in array",
      "Sort K sorted array", "Merge K sorted lists/arrays",
      "Replace each element with greatest on right",
      "Top K frequent elements", "Find K closest elements", "Task Scheduler"
    ]],
    ["11.3", "Hard Problems", [
      "Find median from data stream", "K most frequent words",
      "Maximum sum combination", "Find K pairs with smallest sums",
      "Reorganize string"
    ]]
  ]],
  [12, "Greedy Algorithms", [
    ["12.1", "Easy Problems", [
      "Assign cookies", "Fractional knapsack",
      "Greedy algorithm to find minimum coins", "Lemonade change",
      "Valid parenthesis string", "Jump Game I & II"
    ]],
    ["12.2", "Medium/Hard Problems", [
      "N meetings in one room", "Minimum platforms", "Job sequencing problem",
      "Candy distribution", "Shortest job first (CPU scheduling)",
      "Page faults in LRU", "Insert intervals", "Merge intervals (greedy)",
      "Non-overlapping intervals", "Minimum number of arrows to burst balloons"
    ]]
  ]],
  [13, "Binary Trees", [
    ["13.1", "Traversals", [
      "Introduction to Trees", "Pre-order, In-order, Post-order (recursive)",
      "Level-order traversal (BFS)", "Iterative pre/in/post order",
      "Pre/In/Post in single traversal", "Morris Traversal (in-order, pre-order)",
      "Vertical order traversal", "Top view, Bottom view", "Left view, Right view"
    ]],
    ["13.2", "Medium Problems", [
      "Height of binary tree", "Check if tree is balanced",
      "Diameter of binary tree", "Maximum path sum in BT",
      "Check if two trees are identical", "Zig-Zag level order traversal",
      "Boundary traversal of BT", "Construct BT from preorder+inorder",
      "Construct BT from postorder+inorder", "Symmetric binary tree",
      "Flatten BT to linked list", "Check if BT is mirror of itself",
      "Path to a given node", "Path sum in BT",
      "Lowest Common Ancestor of BT", "Maximum width of binary tree"
    ]],
    ["13.3", "Hard Problems", [
      "Root to node path in BT", "Count nodes in complete BT",
      "Requirements needed to construct unique BT",
      "Print all nodes at K distance from target",
      "Time to burn entire binary tree from a node",
      "Count total nodes in a complete BT",
      "Serialize and deserialize binary tree",
      "Morris Traversal applications", "All nodes at distance K in BT",
      "Vertical width of binary tree", "Maximum sum of non-adjacent nodes",
      "Maximum BST in BT", "Binary tree cameras", "Recover binary tree (swapped nodes)"
    ]]
  ]],
  [14, "Binary Search Trees", [
    ["14.1", "Concepts", [
      "Introduction to BST", "Search in BST", "Find min/max in BST",
      "Ceil and Floor in BST", "Insert a node in BST"
    ]],
    ["14.2", "Practice Problems", [
      "Delete a node from BST", "Find Kth smallest element in BST",
      "Find Kth largest element in BST", "Check if BT is BST or not",
      "LCA of BST", "Construct BST from preorder traversal",
      "Inorder successor/predecessor in BST", "BST iterator",
      "2-sum in BST", "Recover BST (two nodes swapped)",
      "Largest BST in binary tree", "Count BST nodes in a range"
    ]]
  ]],
  [15, "Graphs", [
    ["15.1", "Learning", [
      "Introduction — graph types, terminology", "BFS (Breadth First Search)",
      "DFS (Depth First Search)", "Number of provinces (connected components)",
      "Number of islands", "Flood fill", "Rotten oranges",
      "Detect cycle in undirected graph (BFS/DFS)"
    ]],
    ["15.2", "Topo Sort and Problems", [
      "Detect cycle in directed graph (DFS)", "Topological Sort (DFS)",
      "Topological Sort (BFS / Kahn's Algorithm)",
      "Detect cycle in directed graph (BFS)", "Course Schedule I & II",
      "Find eventual safe states", "Alien dictionary"
    ]],
    ["15.3", "Shortest Path Algorithms", [
      "Shortest path in UG with unit weights",
      "Shortest path in DAG (topo sort based)",
      "Dijkstra's Algorithm (priority queue)", "Dijkstra's Algorithm (set)",
      "Bellman-Ford Algorithm", "Floyd-Warshall Algorithm",
      "Find city with smallest number of neighbors",
      "Cheapest flights within K stops", "Network delay time"
    ]],
    ["15.4", "MinSpanTree / Disjoint Set", [
      "Minimum spanning tree (Prim's Algorithm)",
      "Disjoint Set Union (Union by Rank)",
      "Disjoint Set Union (Union by Size)", "Kruskal's Algorithm",
      "Number of provinces (DSU)", "Making large islands",
      "Most stones removed", "Accounts merge", "Number of islands II",
      "Swim in rising water", "Number of ways to arrive at destination",
      "Minimum multiplications to reach end",
      "Path with maximum probability", "Minimum cost to connect all points"
    ]],
    ["15.5", "Other Algorithms", [
      "Bridges in graph (Tarjan's)", "Articulation points",
      "Kosaraju's Algorithm (SCC)", "Bellman-Ford revisited",
      "Word Ladder I & II", "Number of distinct islands",
      "Bipartite Check (BFS/DFS)", "Strongly connected components",
      "Count strongly connected components", "Number of enclaves",
      "Surrounded regions", "Number of closed islands",
      "Maximum connected group after one change",
      "Truth graph / prerequisites", "M-Coloring problem (graph backtracking)"
    ]]
  ]],
  [16, "Dynamic Programming", [
    ["16.1", "Introduction", [
      "What is DP, memoization vs tabulation", "Climbing stairs",
      "Frog jump (1D DP)", "Frog jump with K distances"
    ]],
    ["16.2", "1D DP", [
      "Maximum sum of non-adjacent elements (house robber)",
      "House robber II (circular)", "Ninja's training",
      "Print the longest increasing subsequence"
    ]],
    ["16.3", "2D / Grid DP", [
      "Unique paths I & II", "Minimum path sum in grid",
      "Triangle / minimum falling path sum", "Chocolate pickup (3D DP)",
      "Minimum/maximum falling path sum", "Cherry pickup II",
      "Maximal square", "Dungeon game"
    ]],
    ["16.4", "DP on Subsequences", [
      "Subset sum equal to K", "Partition equal subset sum",
      "Partition set into 2 subsets (min diff)", "Count subsets with given sum",
      "Count partitions with given difference", "0/1 Knapsack",
      "Minimum coins", "Target sum", "Coin change I & II",
      "Unbounded knapsack", "Rod cutting problem"
    ]],
    ["16.5", "DP on Strings", [
      "Longest Common Subsequence", "Print LCS", "Longest Common Substring",
      "Longest Palindromic Subsequence",
      "Minimum insertions to make string palindrome",
      "Minimum insertions/deletions to convert strings",
      "Shortest common supersequence", "Distinct subsequences",
      "Edit distance", "Wildcard matching"
    ]],
    ["16.6", "DP on Stocks", [
      "Stock buy/sell I (single transaction)",
      "Stock buy/sell II (infinite transactions)",
      "Stock buy/sell III (at most 2 transactions)",
      "Stock buy/sell IV (at most K transactions)",
      "Stock with cooldown", "Stock with transaction fee"
    ]],
    ["16.7", "DP on LIS", [
      "Longest Increasing Subsequence", "Print LIS",
      "LIS using Binary Search O(n log n)", "Largest Divisible Subset",
      "Longest String Chain", "Number of LIS", "Longest Bitonic Subsequence"
    ]],
    ["16.8", "MCM / Partition DP", [
      "Matrix Chain Multiplication", "MCM using memoization",
      "Minimum cost to cut a stick", "Burst balloons",
      "Evaluate boolean expression to true", "Palindrome partitioning II",
      "Partition array for maximum sum"
    ]]
  ]],
  [17, "Tries", [
    ["17.1", "Theory", [
      "Introduction to Trie", "Implement Trie (insert, search, startsWith)",
      "Count distinct substrings using Trie"
    ]],
    ["17.2", "Problems", [
      "Complete string (all prefixes are valid)",
      "Number of distinct substrings",
      "Maximum XOR of two numbers in array",
      "Maximum XOR with an element from array"
    ]]
  ]],
  [18, "String Algorithms", [
    ["18.1", "String Algorithms", [
      "Z-algorithm", "KMP Algorithm — constructing LPS array",
      "KMP Algorithm — string search", "Rabin-Karp algorithm",
      "Shortest palindrome (hard)", "String matching applications"
    ]]
  ]]
];

const PLAYLIST_ID = "PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz";

// Build structured data
let videoIndex = 0;
export const steps = RAW.map(([stepId, stepTitle, subtopics]) => ({
  id: stepId,
  title: `Step ${stepId}: ${stepTitle}`,
  shortTitle: stepTitle,
  subtopics: subtopics.map(([subId, subTitle, videos]) => ({
    id: subId,
    title: subTitle,
    videos: videos.map((title) => {
      videoIndex++;
      return {
        id: `v${videoIndex}`,
        index: videoIndex,
        title,
        stepId,
        subtopicId: subId,
        youtubeUrl: `https://www.youtube.com/watch?v=VIDEO&list=${PLAYLIST_ID}&index=${videoIndex}`
      };
    })
  }))
}));

// Flat list of all videos
export const allVideos = steps.flatMap(s => s.subtopics.flatMap(st => st.videos));
export const TOTAL_VIDEOS = allVideos.length;

// Lookup maps
export const videoById = Object.fromEntries(allVideos.map(v => [v.id, v]));
export const stepById = Object.fromEntries(steps.map(s => [s.id, s]));

export { PLAYLIST_ID };
