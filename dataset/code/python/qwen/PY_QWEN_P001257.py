import sys

def solve():
    s = sys.stdin.readline().strip()
    last_occurrence = {}
    for i, char in enumerate(s):
        last_occurrence[char] = i
        
    partitions = []
    start = 0
    end = 0
    
    for i, char in enumerate(s):
        end = max(end, last_occurrence[char])
        if i == end:
            partitions.append(end - start + 1)
            start = i + 1
            
    print(*partitions)

if __name__ == "__main__":
    solve()

