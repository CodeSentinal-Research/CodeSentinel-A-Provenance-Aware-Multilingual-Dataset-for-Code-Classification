import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    k = int(input_data[1])
    nums = list(map(int, input_data[2:2+n]))
    
    results = []
    for i in range(n - k + 1):
        window = nums[i:i+k]
        s = sum(abs(window[j] - window[j-1]) for j in range(1, k))
        results.append(str(s))
        
    print(" ".join(results))

solve()

