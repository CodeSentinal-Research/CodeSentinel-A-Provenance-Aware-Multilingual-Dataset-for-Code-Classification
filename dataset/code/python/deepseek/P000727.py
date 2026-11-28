Here is a Python solution for the Word Break II problem using Depth-First Search (DFS) approach:

def wordBreak(s, wordDict):
    wordSet = set(wordDict)
    return wordBreakRec(s, wordSet, [])

def wordBreakRec(s, wordSet, currList):
    if len(s) == 0:
        return [''.join(currList)]

    res = []
    for word in wordSet:
        if s.startswith(word):
            s = s[len(word):]
            currList.append(word)
            for end in wordBreakRec(s, wordSet, currList):
                res.append(word + ' ' + end)
            currList.pop()
    return res

s = "catsanddog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
print(wordBreak(s, wordDict))

In this solution, we use the Depth-First Search approach to find all possible sentences. We create a set of valid words to quickly check if a word is in the dictionary. For each word in the dictionary, we check if it's the beginning of the string. If it is, we recursively call the function on the rest of the string and add the word to the current list. Then we return all the sentences by adding a space between the word and the previous sentence.

The time complexity of this solution is O(N * M^2) where N is the length of the string and M is the number of words in the dictionary. The space complexity is also O(N * M^2) due to the recursion stack in the function.