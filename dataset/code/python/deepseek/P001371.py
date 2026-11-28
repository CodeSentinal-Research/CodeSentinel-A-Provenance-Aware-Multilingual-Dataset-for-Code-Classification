def two_sum(nums, target):
    num_dict = dict()
    for i, num in enumerate(nums):
        complement = target - num
        if complement in num_dict:
            return [num_dict[complement], i]
        num_dict[num] = i
    return [-1]

def main():
    N, target = map(int, input().split())
    nums = list(map(int, input().split()))
    print(two_sum(nums, target))

if __name__ == "__main__":
    main()