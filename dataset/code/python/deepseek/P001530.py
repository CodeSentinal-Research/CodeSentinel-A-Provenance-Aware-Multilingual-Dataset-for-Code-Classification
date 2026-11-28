def maxSubarraySum(a):
    max_so_far = a[0]
    curr_max = a[0]
    for i in a[1:]:
        curr_max = max(i, curr_max + i)
        max_so_far = max(max_so_far, curr_max)
    return max_so_far

def main():
    N = int(input().strip())
    a = list(map(int, input().strip().split()))
    print(maxSubarraySum(a))

main()