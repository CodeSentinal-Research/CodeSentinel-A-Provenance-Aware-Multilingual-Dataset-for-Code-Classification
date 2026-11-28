def subsets_recursive(nums, index=0, subset=[], result=[]):
    result.append(list(subset))
    for i in range(index, len(nums)):
        subset.append(nums[i])
        subsets_recursive(nums, i+1, subset, result)
        subset.pop()
    return result

def print_subsets(nums):
    result = subsets_recursive(nums)
    for subset in result:
        print(subset)

def main():
    nums = list(map(int, input("Enter a list of integers (space separated): ").split()))
    print_subsets(nums)

if __name__ == "__main__":
    main()

This code first defines a recursive function `subsets_recursive` that generates all subsets of the input array. The function uses a depth-first search approach to explore all possible subsets.

Then, it defines a function `print_subsets` that calls `subsets_recursive` and prints all the subsets.

Finally, in the `main` function, it takes the input array from the user, calls `print_subsets` with this array, and prints the subsets.