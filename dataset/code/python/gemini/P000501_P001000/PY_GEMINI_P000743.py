import sys
def bubble_sort_rec(arr, n):
    """Sorts the input array into ordered sequence."""
    if n <= 1: return
    for i in range(n - 1):
        if arr[i] > arr[i + 1]:
            arr[i], arr[i + 1] = arr[i + 1], arr[i]
    bubble_sort_rec(arr, n - 1)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        bubble_sort_rec(nums, n)
        print(*nums)
if __name__ == '__main__':
    main()