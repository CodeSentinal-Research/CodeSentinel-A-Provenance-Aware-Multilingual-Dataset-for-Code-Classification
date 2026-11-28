import sys
def is_max_heap(arr, idx):
    n = len(arr)
    l = 2 * idx + 1
    r = 2 * idx + 2
    if l < n:
        if arr[idx] < arr[l] or not is_max_heap(arr, l): return False
    if r < n:
        if arr[idx] < arr[r] or not is_max_heap(arr, r): return False
    return True
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        print("true" if is_max_heap(nums, 0) else "false")
if __name__ == '__main__':
    main()