import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n])); idx += n
    q = int(input_data[idx]); idx += 1
    
    prefix_even = [0] * (n + 1)
    for i in range(n):
        prefix_even[i+1] = prefix_even[i] + (1 if nums[i] % 2 == 0 else 0)
        
    output = []
    for _ in range(q):
        l = int(input_data[idx]); idx += 1
        r = int(input_data[idx]); idx += 1
        output.append(str(prefix_even[r+1] - prefix_even[l]))
        
    print("\n".join(output))

solve()

