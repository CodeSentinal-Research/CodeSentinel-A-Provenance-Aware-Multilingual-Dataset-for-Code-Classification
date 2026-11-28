# problem title : Count Inversions Using Recursive Merge Sort
# Solve the stated task using standard input and standard output.
import sys
def count_inversions(arr):
    def merge_sort(a):
        if len(a) <= 1: return a, 0
        mid = len(a) // 2
        left, inv_l = merge_sort(a[:mid])
        right, inv_r = merge_sort(a[mid:])
        merged = []
        i = j = 0
        inv = inv_l + inv_r
        while i < len(left) and j < len(right):
            if left[i] <= right[j]:
                merged.append(left[i]); i += 1
            else:
                merged.append(right[j])
                inv += len(left) - i
                j += 1
        merged.extend(left[i:])
        merged.extend(right[j:])
        return merged, inv
    _, total_inv = merge_sort(arr)
    return total_inv
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        print(count_inversions(nums))
if __name__ == '__main__':
    main()
