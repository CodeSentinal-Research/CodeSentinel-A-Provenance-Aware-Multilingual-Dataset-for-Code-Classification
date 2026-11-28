import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    positives = [x for x in nums if x > 0]
    negatives = [x for x in nums if x < 0]
    
    result = []
    p_idx = 0
    n_idx = 0
    
    while p_idx < len(positives) and n_idx < len(negatives):
        result.append(positives[p_idx])
        p_idx += 1
        result.append(negatives[n_idx])
        n_idx += 1
        
    result.extend(positives[p_idx:])
    result.extend(negatives[n_idx:])
    
    print(*result)

solve()

