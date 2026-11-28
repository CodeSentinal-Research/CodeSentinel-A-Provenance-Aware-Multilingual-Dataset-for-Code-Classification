import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(str, input_data[1:1+n]))
    
    nums.sort(key=lambda x: x*3, reverse=True)
    
    result = "".join(nums)
    if result[0] == '0':
        print(0)
    else:
        print(result)

if __name__ == "__main__":
    solve()

