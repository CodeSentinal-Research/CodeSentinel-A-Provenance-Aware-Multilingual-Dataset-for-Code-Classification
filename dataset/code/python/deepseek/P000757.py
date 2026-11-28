Here is the Python code for the recursive merge sort algorithm:

def merge_sort(nums):
    if len(nums) <= 1:
        return nums

    mid = len(nums) // 2
    left_half = merge_sort(nums[:mid])
    right_half = merge_sort(nums[mid:])

    return merge(left_half, right_half)

def merge(left, right):
    merged = []
    left_index = right_index = 0

    while left_index < len(left) and right_index < len(right):
        if left[left_index] <= right[right_index]:
            merged.append(left[left_index])
            left_index += 1
        else:
            merged.append(right[right_index])
            right_index += 1

    merged.extend(left[left_index:])
    merged.extend(right[right_index:])

    return merged

def main():
    n = int(input())
    nums = list(map(int, input().split()))
    sorted_nums = merge_sort(nums)
    print(sorted_nums)

if __name__ == "__main__":
    main()

This program first takes an input `n`, followed by `n` space-separated integers for the array `nums`. The `main` function is called at the end to start the program. The `merge_sort` function is the main recursive function that splits the array into two halves, sorts them separately and then merges them. The `merge` function is a helper function that merges two sorted arrays into one.

The program will ask for input `n`, followed by the `n` integers, separated by spaces, and then print the sorted array.