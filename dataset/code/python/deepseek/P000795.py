Here is the Python code for the problem:

def subarraysDivByK(nums, k):
    count = {0: 1}
    prefix_sum = curr = 0
    for num in nums:
        curr = (curr + num % k + k) % k
        count[curr] = count.get(curr, 0) + 1
    return sum(v * (v - 1) // 2 for v in count.values())

This code uses a dictionary to store the count of subarrays ending at each possible remainder of the prefix sum modulo k, and then returns the sum of counts. It handles negative numbers and large numbers correctly because it computes the remainder of the sum modulo k.

The main function to test this function would be:

def main():
    nums = [4,5,0,-2,-3,1]
    k = 5
    print(subarraysDivByK(nums, k))

if __name__ == "__main__":
    main()

This will output: `7`