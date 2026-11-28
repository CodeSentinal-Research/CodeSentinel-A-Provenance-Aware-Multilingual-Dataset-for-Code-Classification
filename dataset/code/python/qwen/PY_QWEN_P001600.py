import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n])); idx += n
    q = int(input_data[idx]); idx += 1
    
    prefix_sum = [0] * (n + 1)
    for i in range(n):
        prefix_sum[i+1] = prefix_sum[i] + nums[i]
        
    output = []
    for _ in range(q):
        l = int(input_data[idx]); idx += 1
        r = int(input_data[idx]); idx += 1
        total = prefix_sum[r+1] - prefix_sum[l]
        count = r - l + 1
        avg = total / count
        if avg == int(avg):
            output.append(str(int(avg)))
        else:
            output.append("{:.2f}".format(avg))
            
    print("\n".join(output))

solve()

