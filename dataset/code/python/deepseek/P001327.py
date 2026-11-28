Here is the Python code for your problem:

def find_subsets(nums):
    nums.sort()

    subsets = [[]]

    for num in nums:
        subsets += [current_subset + [num] for current_subset in subsets]

    subsets = list(dict.fromkeys(subsets))

    for subset in subsets:
        print(subset)


def main():
    n = int(input().strip())

    nums = list(map(int, input().strip().split()))

    find_subsets(nums)


main()

This program takes an integer N as input and then N integers as input. It then calls the `find_subsets` function to find all unique subsets of the list of integers. The subsets are printed in the main function.