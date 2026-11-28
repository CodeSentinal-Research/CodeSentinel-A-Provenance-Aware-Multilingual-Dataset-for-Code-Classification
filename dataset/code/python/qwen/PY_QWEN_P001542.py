import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    k = int(input_data[1])
    nums = list(map(int, input_data[2:2+n]))
    
    current_sum = sum(nums[:k])
    averages = [current_sum / k]
    
    for i in range(k, n):
        current_sum += nums[i] - nums[i-k]
        averages.append(current_sum / k)
        
    print(" ".join("{:.2f}".format(a) for a in averages))

solve()

