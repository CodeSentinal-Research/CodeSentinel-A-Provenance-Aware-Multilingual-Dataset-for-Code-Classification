Here is the Python code:

def single_number(nums):
    bitmask = 0
    for num in nums:
        bitmask ^= num
    rightmost_set_bit = bitmask & -bitmask
    x = 0
    for num in nums:
        if num & rightmost_set_bit:
            x ^= num
    return [x, x ^ bitmask]

nums = list(map(int, input().split()))
print(single_number(nums))

In the above code, we're using bitwise operations to solve the problem. 

The bitmask variable is initialized to 0, and for each number in the array, we're XORing it with the bitmask. The bitmask is then updated to the XOR of itself and the current number. 

The bitmask now holds the XOR of all unique elements in the array.

Then we're finding the rightmost set bit in bitmask and doing a XOR operation with all elements in the array. The result of this operation is the unique elements in the array.