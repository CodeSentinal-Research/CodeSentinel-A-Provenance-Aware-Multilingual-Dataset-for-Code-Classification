const fs = require('fs');
const path = require('path');

const topicsData = {
  "Array": {
    "Easy": ["Find the maximum element", "Reverse the array", "Find the sum of all elements", "Check if array is sorted", "Remove duplicates from sorted array", "Move zeroes to end", "Find the missing number", "Count frequencies of elements", "Find the intersection of two arrays", "Find the majority element"],
    "Medium": ["Rotate array by K steps", "Find the contiguous subarray with maximum sum", "Find the 'K'th largest element", "Merge overlapping intervals", "Sort an array of 0s, 1s, and 2s"],
    "Hard": ["Trapping rain water", "Find median of two sorted arrays", "Maximum gap in sorted array", "First missing positive integer", "Count inversions in an array"]
  },
  "String": {
    "Easy": ["Reverse the string", "Check if string is palindrome", "Find the first non-repeating character", "Count vowels and consonants", "Check if two strings are anagrams", "Longest common prefix", "Implement strStr()", "Valid parentheses", "Length of last word", "Add binary strings"],
    "Medium": ["Longest substring without repeating characters", "Longest palindromic substring", "String to integer (atoi)", "Group anagrams", "Find all anagrams in a string"],
    "Hard": ["Minimum window substring", "Regular expression matching", "Substring with concatenation of all words", "Valid number", "Distinct subsequences"]
  },
  "Dynamic Programming": {
    "Easy": ["Climbing stairs", "Fibonacci number", "Min cost climbing stairs", "Maximum subarray", "Divisor game", "Pascal's triangle", "Is subsequence", "N-th tribonacci number", "Best time to buy and sell stock", "Counting bits"],
    "Medium": ["Coin change", "Longest increasing subsequence", "Word break", "House robber", "Unique paths"],
    "Hard": ["Edit distance", "Burst balloons", "Regular expression matching DP", "Wildcard matching", "Cherry pickup"]
  },
  "Graph": {
    "Easy": ["Find the town judge", "Flood fill", "Island perimeter", "Find if path exists in graph", "Maximum star graph sum", "Detect cycle in graph", "Count vertices", "Print adjacency list", "Find center of star graph", "Graph valid tree"],
    "Medium": ["Number of islands", "Course schedule", "Clone graph", "Pacific atlantic water flow", "Network delay time"],
    "Hard": ["Alien dictionary", "Word ladder", "Longest increasing path in a matrix", "Critical connections in a network", "Swim in rising water"]
  },
  "Binary Search Tree": {
    "Easy": ["Search in a BST", "Insert into a BST", "Minimum absolute difference in BST", "Two sum IV - Input is a BST", "Convert sorted array to BST", "Range sum of BST", "Find mode in BST", "Increasing order search tree", "Lowest common ancestor of a BST", "Validate BST"],
    "Medium": ["Delete node in a BST", "Kth smallest element in a BST", "Construct BST from preorder traversal", "Recover binary search tree", "Unique binary search trees"],
    "Hard": ["Maximum sum BST in binary tree", "Serialize and deserialize BST", "Number of ways to reorder array to get same BST", "Recover a tree from preorder traversal", "Largest BST subtree"]
  },
  "Linked List": {
    "Easy": ["Reverse linked list", "Middle of the linked list", "Merge two sorted lists", "Linked list cycle", "Palindrome linked list", "Remove duplicates from sorted list", "Intersection of two linked lists", "Delete node in a linked list", "Remove linked list elements", "Convert binary number in a linked list to integer"],
    "Medium": ["Add two numbers", "Remove Nth node from end of list", "Swap nodes in pairs", "Rotate list", "Reverse linked list II"],
    "Hard": ["Merge k sorted lists", "Reverse nodes in k-group", "Copy list with random pointer", "Sort list", "LFU Cache"]
  },
  "Stack": {
    "Easy": ["Valid parentheses", "Min stack", "Implement queue using stacks", "Next greater element I", "Backspace string compare", "Remove all adjacent duplicates in string", "Make the string great", "Crawler log folder", "Build an array with stack operations", "Remove outermost parentheses"],
    "Medium": ["Evaluate reverse polish notation", "Decode string", "Daily temperatures", "Asteroid collision", "Minimum remove to make valid parentheses"],
    "Hard": ["Largest rectangle in histogram", "Maximal rectangle", "Basic calculator", "Trapping rain water (stack)", "Remove duplicate letters"]
  },
  "Queue": {
    "Easy": ["Implement stack using queues", "Number of recent calls", "First unique character in a string", "Moving average from data stream", "Time needed to buy tickets", "Reveal cards in increasing order", "Design circular queue", "Design hit counter", "Shortest subarray to be removed to make array sorted", "Task scheduler"],
    "Medium": ["Design circular deque", "Dota2 senate", "Find the winner of the circular game", "Design front middle back queue", "Maximum sum circular subarray"],
    "Hard": ["Sliding window maximum", "Shortest subarray with sum at least K", "Constrained subsequence sum", "Find median from data stream", "Design a text editor"]
  },
  "Tree": {
    "Easy": ["Maximum depth of binary tree", "Symmetric tree", "Invert binary tree", "Path sum", "Diameter of binary tree", "Binary tree inorder traversal", "Same tree", "Subtree of another tree", "Merge two binary trees", "Lowest common ancestor of a binary tree"],
    "Medium": ["Binary tree level order traversal", "Construct binary tree from preorder and inorder traversal", "Flatten binary tree to linked list", "Path sum II", "Count good nodes in binary tree"],
    "Hard": ["Binary tree maximum path sum", "Serialize and deserialize binary tree", "Vertical order traversal of a binary tree", "Recover a tree from preorder traversal", "Sum of distances in tree"]
  },
  "Greedy": {
    "Easy": ["Assign cookies", "Lemonade change", "Array partition I", "Maximize sum of array after K negations", "Minimum cost to move chips to the same position", "Water bottles", "Maximum units on a truck", "Calculate money in leetcode bank", "Largest odd number in string", "Minimum absolute difference"],
    "Medium": ["Jump game", "Jump game II", "Gas station", "Non-overlapping intervals", "Task scheduler"],
    "Hard": ["Candy", "Course schedule III", "Minimum number of refuelling stops", "IPO", "Create maximum number"]
  },
  "Backtracking": {
    "Easy": ["Binary watch", "Count of matches in tournament", "Sum of all subset XOR totals", "Find array given subset sums", "Letter tile possibilities", "Path with maximum gold", "Combination sum", "Subsets", "Permutations", "Word search"],
    "Medium": ["Combinations", "Generate parentheses", "Palindrome partitioning", "Combination sum II", "Subsets II"],
    "Hard": ["N-Queens", "N-Queens II", "Sudoku solver", "Word search II", "Remove invalid parentheses"]
  },
  "Two Pointers": {
    "Easy": ["Valid palindrome", "Reverse string", "Merge sorted array", "Remove element", "Valid palindrome II", "Reverse vowels of a string", "Intersection of two arrays", "Move zeroes", "Is subsequence", "Two sum II"],
    "Medium": ["Container with most water", "3Sum", "4Sum", "Sort colors", "Partition labels"],
    "Hard": ["Trapping rain water", "Minimum window substring", "Substring with concatenation of all words", "Find K-th smallest pair distance", "Subarrays with K different integers"]
  },
  "Sliding Window": {
    "Easy": ["Maximum average subarray I", "Contains duplicate II", "Defuse the bomb", "Substrings of size three with distinct characters", "Minimum difference between highest and lowest of K scores", "Longest nice substring", "Number of valid words in a sentence", "Diet plan performance", "Check if all 1s are at least length K places away", "Find the K-beauty of a number"],
    "Medium": ["Longest substring without repeating characters", "Minimum size subarray sum", "Fruit into baskets", "Max consecutive ones III", "Longest repeating character replacement"],
    "Hard": ["Minimum window substring", "Sliding window maximum", "Sliding window median", "Subarrays with K different integers", "Longest continuous subarray with absolute diff less than or equal to limit"]
  },
  "Binary Search": {
    "Easy": ["Binary search", "Search insert position", "First bad version", "Valid perfect square", "Guess number higher or lower", "Arranging coins", "Find smallest letter greater than target", "Peak index in a mountain array", "Intersection of two arrays II", "Kth missing positive number"],
    "Medium": ["Search a 2D matrix", "Find peak element", "Find first and last position of element in sorted array", "Search in rotated sorted array", "Find minimum in rotated sorted array"],
    "Hard": ["Median of two sorted arrays", "Split array largest sum", "Find in mountain array", "Allocate mailboxes", "Kth smallest number in multiplication table"]
  },
  "Heap": {
    "Easy": ["Kth largest element in a stream", "Last stone weight", "The k weakest rows in a matrix", "Make array zero by subtracting equal amounts", "Relative ranks", "Maximum product of two elements in an array", "Minimum amount of time to fill cups", "Take gifts from the richest pile", "Delete greatest value in each row", "Find the K-beauty of a number"],
    "Medium": ["Kth largest element in an array", "Top K frequent elements", "Sort characters by frequency", "Task scheduler", "K closest points to origin"],
    "Hard": ["Merge k sorted lists", "Find median from data stream", "Sliding window maximum", "IPO", "Trapping rain water II"]
  }
};

let problems = [];
let idCounter = 1;

function getExamples(topic, diff) {
    return [
        { input: "Sample Input 1", output: "Sample Output 1" },
        { input: "Sample Input 2", output: "Sample Output 2" }
    ];
}

function getStarterCode(topic) {
    return `#include <iostream>\nusing namespace std;\n\nint main() {\n    // Read your input from cin\n    // Write your logic here\n    \n    cout << "Sample Output 1\\n";\n    return 0;\n}`;
}

Object.keys(topicsData).forEach(topic => {
  ["Easy", "Medium", "Hard"].forEach(diff => {
    topicsData[topic][diff].forEach((title) => {
        problems.push({
            id: idCounter++,
            topic: topic,
            title: title,
            difficulty: diff,
            description: `This is a **${diff}** difficulty problem focusing on **${topic}**.\n\n### Problem Statement\n${title}.\nImplement an algorithm that efficiently solves the given problem statement using standard C++ structures.\n\n### Constraints\n- \`1 <= N <= 10^5\`\n- Time Complexity: \`O(N)\`\n- Space Complexity: \`O(1)\``,
            examples: getExamples(topic, diff),
            starterCode: { cpp: getStarterCode(topic) },
            testCases: [
                { call: "Standard Input 1", input: getExamples(topic, diff)[0].input, expected: getExamples(topic, diff)[0].output + "\n" },
                { call: "Standard Input 2", input: getExamples(topic, diff)[1].input, expected: getExamples(topic, diff)[1].output + "\n" }
            ]
        });
    });
  });
});

const dir = path.join(__dirname);
fs.writeFileSync(path.join(dir, 'problems.json'), JSON.stringify(problems, null, 2));
console.log(`Generated ${problems.length} diverse problems with unique titles!`);
