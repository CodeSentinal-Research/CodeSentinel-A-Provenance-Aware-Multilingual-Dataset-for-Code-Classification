import sys
def is_sorted_rec(arr, idx):
    """Sorts the input array into ordered sequence."""
    if idx >= len(arr) - 1: return True
    if arr[idx] > arr[idx + 1]: return False
    return is_sorted_rec(arr, idx + 1)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        print("true" if is_sorted_rec(nums, 0) else "false")
if __name__ == '__main__':
    main()