def max_prefixes():
    N = int(input())
    nums = list(map(int, input().split()))

    prefixes = [0] * N
    prefixes[0] = nums[0]
    for i in range(1, N):
        prefixes[i] = prefixes[i-1] + nums[i]

    return max(prefixes)

if __name__ == "__main__":
    print(max_prefixes())