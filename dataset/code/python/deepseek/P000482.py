def nextGreaterElement(nums1, nums2):
    stack = []
    dict_next_greater = {}
    for num in nums2:
        while stack and stack[-1] < num:
            last = stack.pop()
            dict_next_greater[last] = num
        stack.append(num)
    return [dict_next_greater.get(num, -1) for num in nums1]

nums1 = [4,1,2]
nums2 = [1,3,4,2,5]
print(nextGreaterElement(nums1, nums2))  

This Python code uses a stack to track elements in `nums2` and a dictionary to keep track of the next greater element for each element in `nums1`. The main idea is that for every element in `nums2`, we pop elements from the stack until we find an element that is greater than the current element. We then add the current element to the dictionary with the popped elements as the next greater element. After iterating through all elements in `nums2`, we return the next greater element of each element in `nums1`.