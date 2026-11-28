export const INITIAL_SETS = [
  { id: 1, label: "Complete this must", badge: "badge-s1", fill: "fill-s1" },
  { id: 2, label: "Problems on Arrays", badge: "badge-s2", fill: "fill-s2" },
  { id: 3, label: "Problems on Numbers", badge: "badge-s3", fill: "fill-s3" },
  { id: 4, label: "Problems on Number System", badge: "badge-s4", fill: "fill-s4" },
  { id: 5, label: "Problems on Sorting", badge: "badge-s5", fill: "fill-s5" },
  { id: 6, label: "Problems on String", badge: "badge-s6", fill: "fill-s6" }
];

export const INITIAL_QUESTIONS = [];

const ALL_QUESTION_NAMES = {
  1: [],
  2: [
    "Find the smallest number in an array",
    "Find the largest number in an array",
    "Second Smallest and Second Largest element in an array",
    "Reverse a given array",
    "Count frequency of each element in an array",
    "Rearrange array in increasing-decreasing order",
    "Calculate sum of the elements of the array",
    "Rotate array by K elements - Block Swap Algorithm",
    "Average of all elements in an array",
    "Find the median of the given array",
    "Remove duplicates from a sorted array",
    "Remove duplicates from unsorted array",
    "Adding Element in an array",
    "Find all repeating elements in an array",
    "Find all non-repeating elements in an array",
    "Find all symmetric pairs in array",
    "Maximum product subarray in an array",
    "Replace each element of the array by its rank in the array",
    "Sorting elements of an array by frequency",
    "Rotation of elements of array- left and right",
    "Finding equilibrium index of an array",
    "Finding Circular rotation of an array by K positions",
    "Sort an array according to the order defined by another array",
    "Search an element in an array",
    "Check if Array is a subset of another array or not"
  ],
  3: [
    "Check if a number is palindrome or not",
    "Find all Palindrome numbers in a given range",
    "Check if a number is prime or not",
    "Prime numbers in a given range",
    "Check if a number is armstrong number of not",
    "Check if a number is perfect number",
    "Even or Odd",
    "Check weather a given number is positive or negative",
    "Sum of first N natural numbers",
    "Find Sum of AP Series",
    "Program to find sum of GP Series",
    "Greatest of two numbers",
    "Greatest of three numbers",
    "Leap Year or not",
    "Reverse digits of a number",
    "Maximum and Minimum digit in a number",
    "Print Fibonacci upto Nth Term",
    "Factorial of a number",
    "Power of a number",
    "Factors of a given number",
    "Print all prime factors of the given number",
    "Check if a number is a strong number or not",
    "Check if a Number is Automorphic",
    "GCD of two numbers",
    "LCM of two numbers",
    "Check if a number is Harshad number",
    "Check if the number is abundant number or not",
    "Sum of digits of a number",
    "Sum of numbers in the given range",
    "Permutations in which N people can occupy R seats in a classroom",
    "Program to add two fractions",
    "Replace all 0s with 1s in a given integer",
    "Can a number be expressed as a sum of two prime numbers",
    "Calculate the area of circle",
    "Program to find roots of a Quadratic Equation"
  ],
  4: [
    "Convert Binary to Decimal",
    "Convert binary to octal",
    "Decimal to Binary conversion",
    "Convert decimal to octal",
    "Convert octal to binary",
    "Convert octal to decimal",
    "Convert digits/numbers to words"
  ],
  5: [
    "Bubble Sort Algorithm",
    "Selection Sort Algorithm",
    "Insertion Sort Algorithm",
    "Quick Sort Algorithm",
    "Merge sort algorithm"
  ],
  6: [
    "Check if a given string is palindrome or not",
    "Count number of vowels, consonants, spaces in String",
    "Find the ASCII value of a character",
    "Remove all vowels from the string",
    "Remove spaces from a string",
    "Remove characters from a string except alphabets",
    "Reverse a String",
    "Remove brackets from an algebraic expression",
    "Sum of the numbers in a String",
    "Capitalize first and last character of each word",
    "Calculate frequency of characters in a string",
    "Find Non-repeating characters of a String",
    "Check if two strings are anagram of each other",
    "Count common sub-sequence in two strings",
    "Check if two strings match where one string contains wildcard characters",
    "Return maximum occurring character in the input string",
    "Remove all duplicates from the input string.",
    "Print all the duplicates in the input string.",
    "Remove characters from first string present in the second string",
    "Change every letter with the next lexicographic alphabet in the given string",
    "Write a program to find the largest word in a given string.",
    "Write a program to sort characters in a string",
    "Count number of words in a given string",
    "Write a program to find a word in a given string which has the highest number of repeated letters",
    "Change case of each character in a string",
    "Concatenate one string to another",
    "Write a program to find a substring within a string. If found display its starting position",
    "Reverse words in a string"
  ]
};

const LC_MAP = {
  "palindrome or not": "palindrome-number",
  "prime or not": "count-primes",
  "fibonacci upto": "fibonacci-number",
  "reverse words in a string": "reverse-words-in-a-string",
  "reverse a string": "reverse-string",
  "anagram of each other": "valid-anagram",
  "smallest number": "find-minimum-in-rotated-sorted-array",
  "largest number": "find-minimum-in-rotated-sorted-array",
  "triplets with a given sum": "3sum",
  "maximum product subarray": "maximum-product-subarray",
  "duplicates from a sorted array": "remove-duplicates-from-sorted-array"
};

const DIFF_MAP = {
  "palindrome-number": "Easy",
  "count-primes": "Medium",
  "fibonacci-number": "Easy",
  "reverse-words-in-a-string": "Medium",
  "reverse-string": "Easy",
  "valid-anagram": "Easy",
  "3sum": "Medium",
  "maximum-product-subarray": "Medium",
  "remove-duplicates-from-sorted-array": "Easy"
};

export const getFullQuestionDatabase = () => {
  const db = [];

  for (let setId = 1; setId <= 6; setId++) {
    const list = ALL_QUESTION_NAMES[setId] || [];
    list.forEach((name, index) => {
      const id = `s${setId}_${index}`;
      const lowerName = name.toLowerCase();
      
      let slug = null;
      for (const [k, v] of Object.entries(LC_MAP)) {
        if (lowerName.includes(k)) {
          slug = v;
          break;
        }
      }
      
      const difficulty = slug ? DIFF_MAP[slug] || "Easy" : (setId === 5 ? "Medium" : "Easy");
      
      // Starter templates
      const templates = {
        javascript: `function solve(param) {\n  // Write your code here to solve: ${name}\n  return true;\n}`,
        python: `def solve(param):\n    # Write your code here to solve: ${name}\n    return True`,
        cpp: `bool solve() {\n    // Write your code here to solve: ${name}\n    return true;\n}`,
        java: `public class Solution {\n    public static Object solve() {\n        // Write your code here to solve: ${name}\n        return true;\n    }\n}`
      };

      // Add a couple of realistic default test cases
      let testCases = [{ input: "1", expected: "true" }];

      // Customize templates and testcases for standard common problems so that client run works!
      if (lowerName.includes("palindrome or not") && lowerName.includes("number")) {
        templates.javascript = "function solve(n) {\n  const s = n.toString();\n  return s === s.split('').reverse().join('');\n}";
        templates.python = "def solve(n):\n    s = str(n)\n    return s == s[::-1]";
        templates.cpp = "bool solve(int n) {\n    string s = to_string(n);\n    string r = s;\n    reverse(r.begin(), r.end());\n    return s == r;\n}";
        templates.java = "public class Solution {\n    public static boolean solve(int n) {\n        String s = String.valueOf(n);\n        String r = new StringBuilder(s).reverse().toString();\n        return s.equals(r);\n    }\n}";
        testCases = [
          { input: "121", expected: "true" },
          { input: "123", expected: "false" }
        ];
      } else if (lowerName.includes("prime or not")) {
        templates.javascript = "function solve(n) {\n  if (n <= 1) return false;\n  for (let i = 2; i * i <= n; i++) {\n    if (n % i === 0) return false;\n  }\n  return true;\n}";
        templates.python = "def solve(n):\n    if n <= 1: return False\n    for i in range(2, int(n**0.5) + 1):\n        if n % i == 0: return False\n    return True";
        templates.cpp = "bool solve(int n) {\n    if (n <= 1) return false;\n    for (int i = 2; i * i <= n; i++) {\n        if (n % i == 0) return false;\n    }\n    return true;\n}";
        templates.java = "public class Solution {\n    public static boolean solve(int n) {\n        if (n <= 1) return false;\n        for (int i = 2; i * i <= n; i++) {\n            if (n % i == 0) return false;\n        }\n        return true;\n    }\n}";
        testCases = [
          { input: "7", expected: "true" },
          { input: "4", expected: "false" }
        ];
      } else if (lowerName.includes("reverse a string")) {
        templates.javascript = "function solve(s) {\n  return s.split('').reverse().join('');\n}";
        templates.python = "def solve(s):\n    return s[::-1]";
        templates.cpp = "string solve(string s) {\n    reverse(s.begin(), s.end());\n    return s;\n}";
        templates.java = "public class Solution {\n    public static String solve(String s) {\n        return new StringBuilder(s).reverse().toString();\n    }\n}";
        testCases = [
          { input: "'hello'", expected: "olleh" }
        ];
      } else if (lowerName.includes("smallest number in an array")) {
        templates.javascript = "function solve(arr) {\n  return Math.min(...arr);\n}";
        templates.python = "def solve(arr):\n    return min(arr)";
        templates.cpp = "int solve(vector<int> arr) {\n    return *min_element(arr.begin(), arr.end());\n}";
        templates.java = "import java.util.Collections;\nimport java.util.List;\npublic class Solution {\n    public static int solve(List<Integer> arr) {\n        return Collections.min(arr);\n    }\n}";
        testCases = [
          { input: "[5, 3, 9, 1, 7]", expected: "1" }
        ];
      } else if (lowerName.includes("largest number in an array")) {
        templates.javascript = "function solve(arr) {\n  return Math.max(...arr);\n}";
        templates.python = "def solve(arr):\n    return max(arr)";
        templates.cpp = "int solve(vector<int> arr) {\n    return *max_element(arr.begin(), arr.end());\n}";
        templates.java = "import java.util.Collections;\nimport java.util.List;\npublic class Solution {\n    public static int solve(List<Integer> arr) {\n        return Collections.max(arr);\n    }\n}";
        testCases = [
          { input: "[5, 3, 9, 1, 7]", expected: "9" }
        ];
      }

      db.push({
        id,
        name,
        set: setId,
        difficulty,
        lcSlug: slug,
        description: `Practice problem for campus placement preparation: **${name}**.\n\nImplement the solution in the editor to solve this exercise.`,
        templates,
        testCases
      });
    });
  }

  return db;
};
