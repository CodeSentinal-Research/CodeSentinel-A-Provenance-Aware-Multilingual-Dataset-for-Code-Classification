import sys

class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end = False

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    r = int(input_data[idx]); idx += 1
    c = int(input_data[idx]); idx += 1
    
    grid = []
    for _ in range(r):
        grid.append(input_data[idx]); idx += 1
        
    n_words = int(input_data[idx]); idx += 1
    words = []
    for _ in range(n_words):
        words.append(input_data[idx]); idx += 1
        
    root = TrieNode()
    for word in words:
        node = root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.is_end = True
        node.word = word
        
    found = set()
    
    def backtrack(i, j, node):
        char = grid[i][j]
        if char not in node.children:
            return
        next_node = node.children[char]
        if next_node.is_end:
            found.add(next_node.word)
            
        grid[i] = grid[i][:j] + '#' + grid[i][j+1:]
        
        for di, dj in [(1,0), (-1,0), (0,1), (0,-1)]:
            ni, nj = i + di, j + dj
            if 0 <= ni < r and 0 <= nj < c and grid[ni][nj] != '#':
                backtrack(ni, nj, next_node)
                
        grid[i] = grid[i][:j] + char + grid[i][j+1:]
        
    for i in range(r):
        for j in range(c):
            backtrack(i, j, root)
            
    for word in sorted(found):
        print(word)

if __name__ == "__main__":
    solve()

