# problem title : Tug of War Partition
# Solve the stated task using standard input and standard output.
import sys
def tug_of_war(nums):
    n = len(nums)
    total = sum(nums)
    min_diff = [float('inf')]
    best_part = [[]]
    half = n // 2
    def backtrack(idx, count, cur_sum, cur_part):
        if count == half:
            diff = abs(total - 2 * cur_sum)
            if diff < min_diff[0]:
                min_diff[0] = diff
                best_part[0] = list(cur_part)
            return
        if idx == n or (half - count) > (n - idx): return
        backtrack(idx + 1, count + 1, cur_sum + nums[idx], cur_part + [nums[idx]])
        backtrack(idx + 1, count, cur_sum, cur_part)
    backtrack(0, 0, 0, [])
    return min_diff[0], best_part[0]
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        diff, part = tug_of_war(nums)
        print(diff)
        print(*part)
if __name__ == '__main__':
    main()
