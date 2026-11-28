# problem title : Word Ladder Length
# Solve the stated task using standard input and standard output.
from typing import List
from collections import deque

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        words = set(wordList)
        if endWord not in words:
            return 0

        q = deque([(beginWord, 1)])
        visited = {beginWord}

        while q:
            word, length = q.popleft()
            if word == endWord:
                return length
            for i in range(len(word)):
                for c in 'abcdefghijklmnopqrstuvwxyz':
                    next_word = word[:i] + c + word[i+1:]
                    if next_word in words and next_word not in visited:
                        visited.add(next_word)
                        q.append((next_word, length + 1))
        return 0
