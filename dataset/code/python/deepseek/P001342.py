Here is a Python solution that uses a recursive approach to generate all increasing subsequences of length K. The main function reads the input, calls the helper function to generate the subsequences, and prints the subsequences in lexicographical order.

def read_input():
    N, K = map(int, input().split())
    nums = list(map(int, input().split()))
    return N, K, nums

def generate_subsequences(nums, k, start, subsequence, result):
    if len(subsequence) == k:
        result.append(subsequence[:])
        return
    for i in range(start, len(nums)):
        subsequence.append(nums[i])
        generate_subsequences(nums, k, i + 1, subsequence, result)
        subsequence.pop()

def solve():
    N, K, nums = read_input()
    result = []
    generate_subsequences(nums, K, 0, [], result)
    for subsequence in sorted(result):
        print(' '.join(map(str, subsequence)))

if __name__ == "__main__":
    solve()

The `read_input` function reads the input, splitting it into N and K, and the list of N distinct integers.

The `generate_subsequences` function recursively generates all increasing subsequences of length K. It starts at the first index of the nums array, and for each index, it appends the current num to the subsequence, then calls itself recursively with the next index.

The `solve` function reads the input, generates all increasing subsequences of length K, sorts the subsequences in lexicographical order, and prints each subsequence.