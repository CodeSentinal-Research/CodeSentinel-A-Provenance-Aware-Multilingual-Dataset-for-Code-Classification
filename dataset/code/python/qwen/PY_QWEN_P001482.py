import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    power = int(input_data[idx]); idx += 1
    tokens = list(map(int, input_data[idx:idx+n]))
    
    tokens.sort()
    left = 0
    right = n - 1
    score = 0
    max_score = 0
    
    while left <= right:
        if power >= tokens[left]:
            power -= tokens[left]
            score += 1
            left += 1
            max_score = max(max_score, score)
        elif score > 0:
            power += tokens[right]
            score -= 1
            right -= 1
        else:
            break
            
    print(max_score)

solve()

