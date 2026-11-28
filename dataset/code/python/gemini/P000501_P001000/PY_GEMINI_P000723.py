import sys
def can_partition_k_subsets(nums, k):
    total = sum(nums)
    if total % k != 0 or len(nums) < k: return False
    target = total // k
    nums.sort(reverse=True)
    if nums[0] > target: return False
    subsets = [0] * k
    def backtrack(idx):
        if idx == len(nums): return True
        for i in range(k):
            if subsets[i] + nums[idx] <= target:
                subsets[i] += nums[idx]
                if backtrack(idx + 1): return True
                subsets[i] -= nums[idx]
            if subsets[i] == 0: break
        return False
    return backtrack(0)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        k = int(tokens[1+n])
        print("true" if can_partition_k_subsets(nums, k) else "false")
if __name__ == '__main__':
    main()