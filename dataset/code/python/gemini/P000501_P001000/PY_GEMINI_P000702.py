import sys
def count_occ_rec(arr, target, idx):
    if idx >= len(arr): return 0
    return (1 if arr[idx] == target else 0) + count_occ_rec(arr, target, idx + 1)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        target = int(tokens[1+n])
        print(count_occ_rec(nums, target, 0))
if __name__ == '__main__':
    main()