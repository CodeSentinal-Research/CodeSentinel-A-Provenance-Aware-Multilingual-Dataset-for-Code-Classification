Here is the Python code for the problem:

def largest_lucky_number(N, nums):
    freq = {}
    for num in nums:
        if num in freq:
            freq[num] += 1
        else:
            freq[num] = 1

    for num in sorted(freq, reverse=True):
        if freq[num] == num and freq[num] % 2 == 0:
            return num

    return -1

N = int(input().strip())
nums = list(map(int, input().strip().split()))
print(largest_lucky_number(N, nums))

This program first creates a dictionary to store the frequency of each integer in the array. Then, it iterates over the dictionary in reverse order to find the largest lucky integer. If a lucky integer is found (i.e., its frequency is equal to the integer itself and even), it is returned. If no lucky integer is found, -1 is returned.