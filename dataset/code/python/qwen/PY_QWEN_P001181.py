import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    max_reach = 0
    for i in range(n):
        if i > max_reach:
            print("NO")
            return
        max_reach = max(max_reach, i + nums[i])
        
    print("YES")

if __name__ == "__main__":
    solve()

