Here is the Python code for the given problem.

def longestSubarray(nums, k):
    map_sum = dict()
    max_length = 0
    start = 0
    end = 0

    for i in range(len(nums)):
        if nums[i] not in map_sum:
            map_sum[nums[i]] = [i, i]
        else:
            map_sum[nums[i]][1] = i

    for i in range(len(nums)):
        if map_sum[nums[i]][0] + k in map_sum:
            if map_sum[nums[i]][1] - map_sum[nums[i]][0] + 1 > max_length:
                max_length = map_sum[nums[i]][1] - map_sum[nums[i]][0] + 1
                start = map_sum[nums[i]][0]
                end = map_sum[nums[i]][1]

    return end - start + 1 if max_length > 0 else 0

print(longestSubarray([1, -1, 5, 2, 4], 3)) 

In the above code, we use a hash map to store the sum of the subarray and its length. For each number in the array, if the sum is not in the map, we store the sum and its length. If the sum is in the map, we update the ending index of the subarray. After we finish checking all numbers, we return the length of the longest valid subarray.