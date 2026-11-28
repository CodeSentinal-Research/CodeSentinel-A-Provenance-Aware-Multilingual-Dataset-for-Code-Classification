import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    m = int(input_data[idx]); idx += 1
    
    words1 = []
    for _ in range(n):
        words1.append(input_data[idx]); idx += 1
        
    words2 = []
    for _ in range(m):
        words2.append(input_data[idx]); idx += 1
        
    counter1 = Counter(words1)
    counter2 = Counter(words2)
    
    count = 0
    for word in counter1:
        if counter1[word] == 1 and counter2.get(word, 0) == 1:
            count += 1
            
    print(count)

solve()

