import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    distinct_non_zero = len(set(x for x in nums if x != 0))
    print(distinct_non_zero)

if __name__ == "__main__":
    solve()

