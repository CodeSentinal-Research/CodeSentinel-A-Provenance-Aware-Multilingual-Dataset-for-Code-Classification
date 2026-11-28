Here is the Python code for the problem:

def can_partition(nums, k):
    total = sum(nums)
    if total % k != 0:
        return "NO"
    target = total // k
    count = [0] * k
    for num in nums:
        if num > target:
            return "NO"
        count[num % k] += num
    for c in count:
        if c == 0 or c == c % k:
            return "NO"
    return "YES"

def main():
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    print(can_partition(nums, k))

if __name__ == "__main__":
    main()

This code first calculates the total sum of the numbers. If the total sum is not divisible by K, it returns "NO". Otherwise, it calculates the target sum for each subset. Then, it counts the number of each number in the input array and checks if there's any number that exceeds the target sum. If there is, it returns "NO". If none of these conditions are met, it returns "YES".