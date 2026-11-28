import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    k = int(input_data[1])
    nums = list(map(int, input_data[2:2+n]))
    
    count = 0
    current_positives = sum(1 for x in nums[:k] if x > 0)
    if current_positives == k:
        count += 1
        
    for i in range(k, n):
        if nums[i] > 0:
            current_positives += 1
        if nums[i-k] > 0:
            current_positives -= 1
        if current_positives == k:
            count += 1
            
    print(count)

solve()

