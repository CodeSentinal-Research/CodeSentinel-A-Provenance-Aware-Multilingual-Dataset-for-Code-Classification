def top_k_frequent(nums, k):
    count = {}
    for num in nums:
        count[num] = count.get(num, 0) + 1
    nums.sort(key=lambda x: (-count[x], x))
    return nums[:k]

def main():
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    print(top_k_frequent(nums, k))

if __name__ == "__main__":
    main()