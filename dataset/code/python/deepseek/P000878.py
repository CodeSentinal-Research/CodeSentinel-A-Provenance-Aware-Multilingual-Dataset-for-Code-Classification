Here is the Python code for the problem:

def subarrayBitwiseORs(nums):
    res, curr = set(), set()
    for num in nums:
        curr.update([x | num for x in res])
        res.add(num)
    return len(res)

nums = [int(x) for x in input().split()]
print(subarrayBitwiseORs(nums))

This code uses a dictionary to store the set of bitwise ORs for all subarrays, and then returns the length of this set. The set is updated with all the bitwise ORs that have been calculated so far, and the current number is added to the set of all bitwise ORs.

The input for the function is a list of integers, which are separated by spaces in the input. The function is called with this list as input. The result is printed to the console.