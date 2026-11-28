import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    weights = list(map(int, input_data[idx:idx+n]))
    
    splits = []
    for i in range(n - 1):
        splits.append(weights[i] + weights[i+1])
        
    splits.sort()
    
    min_score = sum(weights) + sum(splits[:k-1])
    max_score = sum(weights) + sum(splits[-(k-1):])
    
    print(max_score - min_score)

if __name__ == "__main__":
    solve()

