import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n])); idx += n
    q = int(input_data[idx]); idx += 1
    
    # Prefix sums for even and odd indices separately
    prefix_even = [0] * (n + 1)
    prefix_odd = [0] * (n + 1)
    
    for i in range(n):
        prefix_even[i+1] = prefix_even[i]
        prefix_odd[i+1] = prefix_odd[i]
        if i % 2 == 0:
            prefix_even[i+1] += nums[i]
        else:
            prefix_odd[i+1] += nums[i]
            
    output = []
    for _ in range(q):
        l = int(input_data[idx]); idx += 1
        r = int(input_data[idx]); idx += 1
        
        # Sum of elements at even relative positions from l? 
        # "alternate positions... starting from left endpoint"
        # Indices l, l+2, l+4...
        
        s = 0
        for i in range(l, r + 1, 2):
            s += nums[i]
        output.append(str(s))
        
    print("\n".join(output))

solve()

