
'''
Count Distinct Substrings of a String using Trie
Given a string s, the task is to count all distinct substrings of the given string using Trie data structure. A substring is a contiguous sequence of characters within a string. For example, the distinct substrings of the string "abc" are "a", "b", "c", "ab", "bc", and "abc". The total number of distinct substrings is 6.

Example 1:
Input: s = "ab"
Output: 3
Explanation: The distinct substrings are "a", "b", and "ab".

Example 2:
Input: s = "aab"
Output: 6
Explanation: The distinct substrings are "a", "aa", "ab", "b", "aa", and "aab".

Constraints:
1 <= s.length <= 1000
s consists of lowercase English letters.

Intuition:
We can use a Trie data structure to efficiently store and count distinct substrings of a given string. By inserting all suffixes of the string into the Trie, we can ensure that each unique substring is represented in the Trie. The number of distinct substrings can then be calculated based on the number of nodes in the Trie.

Approach:
1. Create a Trie data structure with methods to insert suffixes and count distinct substrings.
2. Insert all suffixes of the input string into the Trie.
3. The number of distinct substrings can be calculated by counting the number of nodes in the Trie, as each node represents a unique substring.
4. Return the count of distinct substrings. 

Complexity Analysis:

Time Complexity:
Inserting all suffixes into the Trie takes O(N^2) time, where N is the length of the string. This is because there are N suffixes, and inserting each suffix takes O(N) time in the worst case.

Space Complexity:
The space complexity is O(N^2), where N is the length of the string, as we need to store all the suffixes in the Trie.

'''


class trieNode:
    def __init__(self):
        
        self.children = {}

class Trie:
    def __init__(self):
        self.root = trieNode()
    
    def insert(self, word):
        node = self.root

        sub_str_cnt = 0


        for char in word:
            if char not in node.children:
                node.children[char] = trieNode()
                sub_str_cnt +=1
            node = node.children[char]
        return sub_str_cnt

def countDistinctSubstrings(s):
    
    trie = Trie()

    result = 0

    for i in range(len(s)):
        suffix = s[i:]
        result += trie.insert(suffix)
    return result + 1