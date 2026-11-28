Here is the Python code with the main function and input handling:

def countSubarrays(nums, k):
    count = 0
    prefix_mod_k = {0: 1}
    cur_sum = 0

    for num in nums:
        cur_sum += num
        mod_k = cur_sum % k

        count += prefix_mod_k.get(mod_k, 0)

        prefix_mod_k[mod_k] = prefix_mod_k.get(mod_k, 0) + 1

    return count


def main():
    N, K = map(int, input().split())
    nums = list(map(int, input().split()))

    print(countSubarrays(nums, K))


if __name__ == "__main__":
    main()

In this code, `prefix_mod_k` is a dictionary that stores the count of prefix sum modulo k. We iterate over each number in the array and update the sum modulo k. For each mod_k, if it exists in the dictionary, it means there are prefix sum modulo k equal to mod_k, and there is one subarray ending at the current number that is divisible by k. We increase the count by this number. Otherwise, we add the mod_k to the dictionary.