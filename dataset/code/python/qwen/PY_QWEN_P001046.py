import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    arr = list(map(int, input_data[1:1+n]))
    
    root = arr[0]
    count = 0
    for x in arr:
        if x > root:
            count += 1
            
    print(count)

if __name__ == "__main__":
    solve()

