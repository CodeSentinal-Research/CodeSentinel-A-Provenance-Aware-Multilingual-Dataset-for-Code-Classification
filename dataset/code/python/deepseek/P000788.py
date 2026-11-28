Here is the Python code:

def findMaxAverage(nums, k):
    if not nums or k > len(nums):
        return None

    total = sum(nums[:k])
    max_avg = total / k

    for i in range(k, len(nums)):
        total -= nums[i - k]
        total += nums[i]
        max_avg = max(max_avg, total / k)

    return max_avg

def main():
    nums = list(map(int, input("Enter numbers separated by space: ").split()))
    k = int(input("Enter the length of the subarray: "))

    print("Maximum Average: ", findMaxAverage(nums, k))

if __name__ == "__main__":
    main()

In this Python code, the `findMaxAverage` function takes an array of integers and an integer `k` as input and returns the maximum average of a contiguous subarray of length `k`. The `main` function reads the array of integers and the length of the subarray from the user and prints the maximum average.