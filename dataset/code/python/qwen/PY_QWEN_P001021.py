import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    arr = list(map(int, input_data[1:1+n]))
    i = int(input_data[1+n])
    new_val = int(input_data[2+n])
    
    arr[i] = new_val
    
    # Sift up for max heap
    while i > 0:
        parent = (i - 1) // 2
        if arr[parent] < arr[i]:
            arr[parent], arr[i] = arr[i], arr[parent]
            i = parent
        else:
            break
            
    print(*arr)

if __name__ == "__main__":
    solve()

