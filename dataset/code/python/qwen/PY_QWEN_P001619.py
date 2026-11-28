import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n])); idx += n
    q = int(input_data[idx]); idx += 1
    
    prefix_xor = [0] * (n + 1)
    for i in range(n):
        prefix_xor[i+1] = prefix_xor[i] ^ nums[i]
        
    output = []
    for _ in range(q):
        l = int(input_data[idx]); idx += 1
        r = int(input_data[idx]); idx += 1
        output.append(str(prefix_xor[r+1] ^ prefix_xor[l]))
        
    print("\n".join(output))

solve()

