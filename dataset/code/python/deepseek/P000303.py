Here is the Python code for the given problem:

def wordBreak(s, wordDict):
    def dfs(s, wordDict, path, res):
        if not s:
            res.append(path)
            return
        for word in wordDict:
            if s.startswith(word):
                dfs(s[len(word):], wordDict, path+' '+word, res)

    res = []
    dfs(s, wordDict, '', res)
    return res

print(wordBreak('catsanddog', ['cats', 'dog', 'sand', 'and', 'cat']))

This program uses Depth-First Search (DFS) approach to solve the problem. It checks each word in the dictionary if it starts with the given string. If it does, it recursively calls the function for the remaining string. The path is appended with the word to represent the current phrase.

The function `dfs` takes 4 parameters: the remaining string `s`, the dictionary `wordDict`, the current path `path`, and the result list `res`.

In each recursive call, if the string `s` is empty, it means we have reached the end of the string and the current path is a valid phrase, so we append it to the result list.

Otherwise, for each word in the dictionary, if the word starts with the current string `s`, we recursively call `dfs` on the remaining string (`s[len(word):]`), and append the word to the current path (`path+' '+word`).

Finally, the function returns the result list.

The test case `wordBreak('catsanddog', ['cats', 'dog', 'sand', 'and', 'cat'])` outputs `['cats and dog', 'cat sand dog']`.