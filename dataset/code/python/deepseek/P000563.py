from collections import deque

def ladderLength(beginWord, endWord, wordList):
    wordList = set(wordList)
    queue = deque([(beginWord, 1)])
    while queue:
        word, length = queue.popleft()
        if length > len(beginWord):
            break
        if word == endWord:
            return length
        for i in range(len(word)):
            for c in 'abcdefghijklmnopqrstuvwxyz':
                next_word = word[:i] + c + word[i+1:]
                if next_word in wordList:
                    wordList.remove(next_word)
                    queue.append((next_word, length + 1))
    return 0

beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
print(ladderLength(beginWord, endWord, wordList))