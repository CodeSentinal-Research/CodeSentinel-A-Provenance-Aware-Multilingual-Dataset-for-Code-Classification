Here is the Python code for the problem:

def find_subsets(nums):
    output = []
    subset_sum(nums, 0, 0, output)
    output.sort()
    return output

def subset_sum(nums, start, total, output):
    if start == len(nums):
        return
    subset_sum(nums, start+1, total + nums[start], output)
    output.append(total)
    subset_sum(nums, start+1, total, output)

def main():
    nums = list(map(int, input("Enter numbers in array, separated by space: ").split()))
    print(find_subsets(nums))

if __name__ == "__main__":
    main()

This program asks the user to input a list of integers, separated by spaces. It then calls the `find_subsets` function, passing the list of integers. The `find_subsets` function calls the `subset_sum` function, which recursively generates all possible subsets of the list. It then sorts the subset sums and returns them in a sorted list. Finally, the `main` function handles input and output, and calls the `find_subsets` function.