# problem title : Word Search II
# Solve the stated task using standard input and standard output.
from typing import List

class TrieNode:
    def __init__(self):
        self.children = {}
        self.word = None

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        root = TrieNode()
        for w in words:
            node = root
            for c in w:
                if c not in node.children:
                    node.children[c] = TrieNode()
                node = node.children[c]
            node.word = w

        m, n = len(board), len(board[0])
        res = []

        def dfs(r: int, c: int, node: TrieNode):
            ch = board[r][c]
            if ch not in node.children:
                return

            curr = node.children[ch]
            if curr.word:
                res.append(curr.word)
                curr.word = None

            board[r][c] = "#"
            for dr, dc in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < m and 0 <= nc < n and board[nr][nc] != "#":
                    dfs(nr, nc, curr)
            board[r][c] = ch

        for i in range(m):
            for j in range(n):
                dfs(i, j, root)

        return res
