Here is the Python code:

def totalHammingDistance(nums):
    total = 0
    for i in range(32):
        bit_count_ones = 0
        bit_count_zeros = 0
        for num in nums:
            if (num >> i) & 1:
                bit_count_ones += 1
            else:
                bit_count_zeros += 1
        total += bit_count_ones * bit_count_zeros
    return total

The function `totalHammingDistance` takes an array of integers as input. It then iterates over each possible bit position (from least significant bit to most significant bit), for each bit position, it counts the number of elements in the array that have that bit set. It then multiplies these counts together (the number of elements with a '1' in the current bit position) by the number of elements with a '0' in the current bit position to get the total Hamming distance. It adds this to the total sum.

The time complexity of this solution is O(n), where n is the size of the input array. The space complexity is also O(1), because no additional space is used, but the time complexity is also O(n).