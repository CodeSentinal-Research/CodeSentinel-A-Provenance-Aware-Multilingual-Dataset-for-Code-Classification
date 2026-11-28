Here is a Python solution using a deque from collections to keep track of the maximums of each subarray of size k:

from collections import deque

def max_in_window(nums, k):
    if not nums or k <= 0 or k > len(nums):
        return []

    max_deque = deque()
    res = []
    for i in range(len(nums)):
        if max_deque and max_deque[0] == i - k:
            max_deque.popleft()
        while max_deque and nums[max_deque[-1]] < nums[i]:
            max_deque.pop()
        max_deque.append(i)

        if i >= k - 1:
            res.append(nums[max_deque[0]])

    return res

In the main function, you can pass the array and the window size like this:

def main():
    nums = [1, 3, -1, -3, 5, 3, -1]
    k = 3
    print(max_in_window(nums, k))  

if __name__ == "__main__":
    main()

Please note that the window starts at the first element and ends at the (k-1)th element. For example, if k is 3, the window starts at the first three elements and ends at the third.