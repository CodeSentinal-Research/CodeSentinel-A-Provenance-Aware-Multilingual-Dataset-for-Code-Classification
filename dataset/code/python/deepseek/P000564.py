Here's the Python code:

from collections import deque

def is_equal(s1, s2):
    diff = sum(1 for a, b in zip(s1, s2) if a == b)
    return diff == 1

def ladderLength(self, beginWord, endWord, wordList):
    wordList = set(wordList)
    queue = deque([(beginWord, [beginWord])])
    while queue:
        current_word, path = queue.popleft()
        if is_equal(current_word, endWord):
            return path
        for next_word in self.get_next_words(current_word, wordList):
            if next_word not in path:
                queue.append((next_word, path + [next_word]))

def get_next_words(self, current_word, wordList):
    for i in range(len(current_word)):
        for char in 'abcdefghijklmnopqrstuvwxyz':
            next_word = current_word[:i] + char + current_word[i+1:]
            if next_word in wordList:
                yield next_word

This code uses Breadth-First Search (BFS) to find all shortest transformation sequences from beginWord to endWord. It uses a deque to store the words to be processed in each level, starting from beginWord.

The `is_equal` function checks whether two words are equal by comparing them letter by letter.

`ladderLength` function creates a queue and enqueues the beginWord with its path as the first element. Then it enters a loop where it dequeues a word, checks if the current word is the target word, and if not, generates next words for the current word and adds them to the queue with the path updated.

`get_next_words` function generates all possible next words for a given current word and filters out those not in the given wordList.