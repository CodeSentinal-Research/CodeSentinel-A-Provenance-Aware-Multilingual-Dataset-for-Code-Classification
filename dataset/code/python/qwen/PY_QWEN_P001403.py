import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    q = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n])); idx += n
    
    output = []
    for _ in range(q):
        l = int(input_data[idx]); idx += 1
        r = int(input_data[idx]); idx += 1
        sub = sorted(nums[l-1:r])
        is_arithmetic = True
        if len(sub) > 2:
            diff = sub[1] - sub[0]
            for i in range(2, len(sub)):
                if sub[i] - sub[i-1] != diff:
                    is_arithmetic = False
                    break
        output.append("YES" if is_arithmetic else "NO")
        
    print("\n".join(output))

solve()

