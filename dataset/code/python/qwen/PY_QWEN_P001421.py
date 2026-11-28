import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    list1 = []
    for _ in range(n):
        list1.append(input_data[idx]); idx += 1
        
    m = int(input_data[idx]); idx += 1
    list2 = []
    for _ in range(m):
        list2.append(input_data[idx]); idx += 1
        
    map2 = {word: i for i, word in enumerate(list2)}
    
    min_sum = float('inf')
    results = []
    
    for i, word in enumerate(list1):
        if word in map2:
            s = i + map2[word]
            if s < min_sum:
                min_sum = s
                results = [word]
            elif s == min_sum:
                results.append(word)
                
    for word in results:
        print(word)

solve()

