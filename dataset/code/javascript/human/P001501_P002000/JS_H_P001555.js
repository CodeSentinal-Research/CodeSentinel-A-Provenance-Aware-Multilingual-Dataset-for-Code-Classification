// 1. Reverse a String

/**
 * @param {string} str
 * @return {string}
 */
function reverseString(str) {
  return str.split("").reverse().join("");
}

// 2. Find Maximum

/**
 * @param {number[]} nums
 * @return {number}
 */
function findMax(nums) {
  let max = nums[0];

  for (let num of nums) {
    if (num > max) {
      max = num;
    }
  }

  return max;
}

// 3. Check for Palindrome

/**
 * @param {string} str
 * @return {boolean}
 */
function isPalindrome(str) {
  let reversed = str.split("").reverse().join("");

  return str === reversed;
}

// 4. Sum Array Elements

/**
 * @param {number[]} nums
 * @return {number}
 */
function sumArray(nums) {
  let sum = 0;

  for (let num of nums) {
    sum = sum + num;
  }

  return sum;
}

// 5. Count Vowels

/**
 * @param {string} str
 * @return {number}
 */
function countVowels(str) {
  let count = 0;

  for (let char of str.toLowerCase()) {
    if ("aeiou".includes(char)) {
      count++;
    }
  }

  return count;
}

// 6. Two Sum

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
function twoSum(nums, target) {
  for (let i = 0; i < nums.length; i++) {
    for (let j = i + 1; j < nums.length; j++) {
      if (nums[i] + nums[j] === target) {
        return [i, j];
      }
    }
  }

  return [];
}

// 7. Flatten a Nested Array

/**
 * @param {Array} arr
 * @return {Array}
 */
function flattenArray(arr) {
  return arr.flat(Infinity);
}

// 8. Group Anagrams

/**
 * @param {string[]} strs
 * @return {string[][]}
 */
function groupAnagrams(strs) {
  let groups = {};

  for (let str of strs) {
    let key = str.split("").sort().join("");

    if (!groups[key]) {
      groups[key] = [];
    }

    groups[key].push(str);
  }

  return Object.values(groups);
}

// 9. Longest Substring Without Repeating Characters

/**
 * @param {string} s
 * @return {number}
 */
function lengthOfLongestSubstring(s) {
  let start = 0;
  let maxLength = 0;
  let chars = new Set();

  for (let end = 0; end < s.length; end++) {
    while (chars.has(s[end])) {
      chars.delete(s[start]);
      start++;
    }

    chars.add(s[end]);

    let length = end - start + 1;

    if (length > maxLength) {
      maxLength = length;
    }
  }

  return maxLength;
}

// 10. Deep Clone an Object

/**
 * @param {Object} obj
 * @return {Object}
 */
function deepClone(obj) {
  return JSON.parse(JSON.stringify(obj));
}

/*=====================Output====================*/

console.log("1. Reverse:", reverseString("hello"));

console.log("2. Maximum:", findMax([3, 7, 2, 9, 5]));

console.log("3. Palindrome:", isPalindrome("racecar"));

console.log("4. Sum:", sumArray([10, 20, 30, 40]));

console.log("5. Vowels:", countVowels("javascript"));

console.log("6. Two Sum:", twoSum([2, 7, 11, 15], 9));

console.log("7. Flatten:", flattenArray([1, [2, [3, 4], 5]]));

console.log(
  "8. Anagrams:",
  groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]),
);

console.log("9. Longest Substring:", lengthOfLongestSubstring("abcabcbb"));

console.log("10. Deep Clone:", deepClone({a: 1, b: {c: 2}}));