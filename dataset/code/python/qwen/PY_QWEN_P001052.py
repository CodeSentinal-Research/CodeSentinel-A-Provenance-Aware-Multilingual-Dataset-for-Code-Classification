import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    arr = list(map(int, input_data[1:1+n]))
    
    # Check Max Heap property on level order (array)
    is_max_heap = True
    for i in range(n):
        left = 2 * i + 1
        right = 2 * i + 2
        if left < n and arr[i] < arr[left]:
            is_max_heap = False
            break
        if right < n and arr[i] < arr[right]:
            is_max_heap = False
            break
            
    print("YES" if is_max_heap else "NO")

if __name__ == "__main__":
    solve()

