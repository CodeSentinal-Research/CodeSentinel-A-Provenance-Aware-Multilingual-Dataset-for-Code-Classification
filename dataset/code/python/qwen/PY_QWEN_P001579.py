import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    count_neg = sum(1 for x in nums[:k] if x < 0)
    max_neg = count_neg
    
    for i in range(k, n):
        if nums[i] < 0:
            count_neg += 1
        if nums[i-k] < 0:
            count_neg -= 1
        max_neg = max(max_neg, count_neg)
        
    print(max_neg)

solve()

