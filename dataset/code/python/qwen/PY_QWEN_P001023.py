import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    arr = list(map(int, input_data[1:1+n]))
    i = int(input_data[1+n])
    
    if i == 0:
        print(-1)
    else:
        parent_idx = (i - 1) // 2
        print(arr[parent_idx])

if __name__ == "__main__":
    solve()

