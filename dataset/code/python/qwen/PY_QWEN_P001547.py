import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    k = int(input_data[1])
    nums = list(map(int, input_data[2:2+n]))
    
    current_odds = sum(1 for x in nums[:k] if x % 2 != 0)
    max_odds = current_odds
    
    for i in range(k, n):
        if nums[i] % 2 != 0:
            current_odds += 1
        if nums[i-k] % 2 != 0:
            current_odds -= 1
        max_odds = max(max_odds, current_odds)
        
    print(max_odds)

solve()

