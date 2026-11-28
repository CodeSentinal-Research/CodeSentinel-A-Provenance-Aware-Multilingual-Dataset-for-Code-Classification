import sys
from collections import deque

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    words = set()
    for _ in range(n):
        words.add(input_data[idx]); idx += 1
        
    start_word = input_data[idx]; idx += 1
    end_word = input_data[idx]; idx += 1
    
    if end_word not in words:
        print(0)
        return
        
    q = deque([(start_word, 1)])
    visited = set([start_word])
    
    while q:
        word, steps = q.popleft()
        if word == end_word:
            print(steps)
            return
        for i in range(len(word)):
            for c in 'abcdefghijklmnopqrstuvwxyz':
                if c != word[i]:
                    new_word = word[:i] + c + word[i+1:]
                    if new_word in words and new_word not in visited:
                        visited.add(new_word)
                        q.append((new_word, steps + 1))
                        
    print(0)

if __name__ == "__main__":
    solve()

