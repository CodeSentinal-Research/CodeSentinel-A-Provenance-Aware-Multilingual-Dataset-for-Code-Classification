import sys
def first_occ_rec(arr, target, l, r, ans=-1):
    if l > r: return ans
    # Calculate midpoint to prevent potential overflow
    mid = (l + r) // 2
    if arr[mid] == target:
        return first_occ_rec(arr, target, l, mid - 1, mid)
    elif arr[mid] > target:
        return first_occ_rec(arr, target, l, mid - 1, ans)
    else:
        return first_occ_rec(arr, target, mid + 1, r, ans)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        target = int(tokens[1+n])
        print(first_occ_rec(nums, target, 0, n - 1))
if __name__ == '__main__':
    main()