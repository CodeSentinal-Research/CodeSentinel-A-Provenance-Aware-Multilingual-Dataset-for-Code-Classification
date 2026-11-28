Here is the Python code with input handling.

def find_subsequence(nums, target):
    def find_subsequence_recursive(nums, target, start, path, res):
        if target == 0 and len(path) == len(nums):
            res.append(path)
            return
        if target < 0 or len(path) == len(nums):
            return
        for i in range(start, len(nums)):
            find_subsequence_recursive(nums, target - nums[i], i, path + [nums[i]], res)

    res = []
    find_subsequence_recursive(nums, target, 0, [], res)
    return res if res else -1

def main():
    nums = [1, 2, 3, 4, 5]
    target = 5
    print(find_subsequence(nums, target))

if __name__ == "__main__":
    main()

In this code, we recursively find all subsequences of the given sequence that sum up to the target. If we find such a subsequence, we add it to our results. If no such subsequence is found, we return -1. The `main` function is for testing and input handling.