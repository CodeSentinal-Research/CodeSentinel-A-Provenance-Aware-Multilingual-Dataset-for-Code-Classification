import sys

def solve():
    word = sys.stdin.readline().strip()
    ch = sys.stdin.readline().strip()
    
    idx = word.find(ch)
    if idx == -1:
        print(word)
    else:
        prefix = word[:idx+1]
        suffix = word[idx+1:]
        print(prefix[::-1] + suffix)

solve()

