import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    sweetness = list(map(int, input_data[idx:idx+n]))
    
    low = min(sweetness)
    high = sum(sweetness)
    
    def can_split(min_sweet):
        cuts = 0
        current_sum = 0
        for s in sweetness:
            current_sum += s
            if current_sum >= min_sweet:
                cuts += 1
                current_sum = 0
        return cuts >= k + 1
        
    result = 0
    while low <= high:
        mid = (low + high) // 2
        if can_split(mid):
            result = mid
            low = mid + 1
        else:
            high = mid - 1
            
    print(result)

if __name__ == "__main__":
    solve()

