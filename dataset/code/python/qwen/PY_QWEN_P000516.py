import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:n+1]))
    sorted_nums = sorted(nums)
    l, r = 0, n - 1
    while l < n and nums[l] == sorted_nums[l]: l += 1
    while r >= 0 and nums[r] == sorted_nums[r]: r -= 1
    print(r - l + 1 if l < n else 0)
solve()
