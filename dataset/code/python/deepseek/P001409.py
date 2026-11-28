Here is the Python code for the problem:

def count_pairs(N, K, nums):
    count = 0
    nums_dict = {}
    for num in nums:
        if num in nums_dict:
            count += nums_dict[num]
            nums_dict[num+K] = nums_dict.get(num+K, 0) + 1
        else:
            nums_dict[num] = nums_dict.get(num, 0) + 1
    return count

def main():
    N, K = map(int, input().split())
    nums = list(map(int, input().split()))
    print(count_pairs(N, K, nums))

if __name__ == "__main__":
    main()

This code first reads the integers N and K, then the array of integers. It then calls the `count_pairs` function, which counts the number of valid pairs, and prints the result.