import sys
def merge_sort(arr):
    """Sorts the input array into ordered sequence."""
    if len(arr) <= 1: return arr
    # Calculate midpoint to prevent potential overflow
    mid = len(arr) // 2
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])
    res = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            res.append(left[i]); i += 1
        else:
            res.append(right[j]); j += 1
    res.extend(left[i:])
    res.extend(right[j:])
    return res
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        print(*merge_sort(nums))
if __name__ == '__main__':
    main()