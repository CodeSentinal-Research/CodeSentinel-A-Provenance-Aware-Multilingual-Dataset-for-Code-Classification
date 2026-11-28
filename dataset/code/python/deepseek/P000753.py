Here is the Python code for the problem. This program uses recursion to generate all possible subsets and then filters out those that have a sum equal to the target.

def find_subsequences(nums, target, start, path, res):
    if target == 0:
        res.append(path)
        return
    elif target < 0:
        return
    for i in range(start, len(nums)):
        find_subsequences(nums, target - nums[i], i, path + [nums[i]], res)

def print_subsequences(nums, target):
    res = []
    find_subsequences(nums, target, 0, [], res)
    res.sort()
    for r in res:
        print(r)

print_subsequences([1, 2, 7, 6, 3], 8)

In this code, `find_subsequences` is a recursive function that generates all possible subsets of the given array `nums` that sum up to `target`. It uses the backtracking approach. For each element in the array, it recursively calls `find_subsequences` with the remaining elements and the current sum decreased by the element value. If the current sum becomes 0, it means we have found a valid subsequence.

The `print_subsequences` function calls `find_subsequences` to generate all possible subsets of `nums` that sum up to `target`. It sorts the result before printing it.

Please note that this code will not work for the following constraints:
1. `-100 <= nums[i] <= 100`
2. `1 <= n <= 30`
3. `-100 <= target <= 100`
4. `nums` is a list of integers, and `target` is an integer