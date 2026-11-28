"""
Easy array problems

"""

"""
1. Find the Largest element in an array
"""
from typing import Literal
def largest(array:list[int])->int:
    max:int = array[0]
    for i in range(0,len(array)):
        if array[i] > max: 
            max = array[i]
    
    return max


# print(largest([2,4,1,2,45,3,12]))

"""
2. Find the second Largest element in an array without sorting
"""

def second_largest(array:list[int])->int:
    if(len(array) < 2):
        raise ValueError("Array must have atlest 2 elements")
    
    large = float('-inf')
    second_large = float('-inf')

    for i in range(len(array)):
        if array[i] > large:
            second_large = large
            large = array[i]
        elif array[i] > second_large and array[i] != large:
            second_large = array[i]
        
    return int(second_large)

# print(second_largest([2,34,2,22]))
    

"""
3. Check if the array is sorted
"""
def check_sorted(array:list[int])->bool:
    for i in range(len(array)-1):
        if array[i]<array[i+1]:
            return False
    return True


# print(check_sorted([2,3,6,5]))

"""
4. Remove duplicates from a sorted array
"""

def remove_duplicates(array:list[int])-> list[int]:
    if len(array) < 2:
        return array
    
    i = 0
    for j in range(1, len(array)):
        if array[j] != array[i]:
            i+=1
            array[i] = array[j]
        
    return array[:i+1]

# print(remove_duplicates([1,1,2,2,3,3,4,4,5,6,7,8]))

"""
5. Left rotate an array

"""

def left_rotate(array:list[int])-> list[int]:
    if len(array) < 2:
        return array
    
    temp = array[0]
    for j in range(len(array)-1):
        array[j] = array[j+1]
    
    array[-1] = temp

    return array

# print(left_rotate([1,2,3,4,5]))



"""
7. Rotate an array k times with side

"""


def reverse(nums: list[int], start: int, end: int) -> None:
    """Helper function to reverse a portion of the list in-place."""
    while start < end:
        nums[start], nums[end] = nums[end], nums[start]
        start += 1
        end -= 1

def rotate_array(nums: list[int], k: int, side: Literal["left", "right"]) -> list[int]:
    n = len(nums)
    if n < 2:
        return nums

    # Normalize k to handle rotations larger than the array length
    k %= n
    if k == 0:
        return nums

    if side == "right":
        # 1. Reverse the entire array
        reverse(nums, 0, n - 1)
        # 2. Reverse the first k elements
        reverse(nums, 0, k - 1)
        # 3. Reverse the remaining elements
        reverse(nums, k, n - 1)
        
    elif side == "left":
        # 1. Reverse the first k elements
        reverse(nums, 0, k - 1)
        # 2. Reverse the remaining elements
        reverse(nums, k, n - 1)
        # 3. Reverse the entire array
        reverse(nums, 0, n - 1)

    return nums



"""
8. Move Zeros
Input: 1 ,0 ,2 ,3 ,0 ,4 ,0 ,1
Output: 1 ,2 ,3 ,4 ,1 ,0 ,0 ,0
"""
def move_zeros(array: list[int]) -> list[int]:
    # Pointer to track where the next non-zero element should be placed
    insert_pos = 0
    
    # Iterate through the array exactly once
    for i in range(len(array)):
        # If we find a non-zero number, we swap it to the insert position
        if array[i] != 0:
            array[insert_pos], array[i] = array[i], array[insert_pos]
            insert_pos += 1
            
    return array

"""
9. Linear Search

"""

def linear_search(array:list[int], key:int) -> bool:
    if key in array:
        return True
    return False



"""
10. Union of two arrays

"""

class UnionArrays:
    def find_union_bruteForce(self, array1:list[int],array2:list[int]) -> list[int]:
        freq = {}

        for x in array1:
            freq[x] = freq.get(x,0) + 1
        
        for x in array2:
            freq[x] = freq.get(x,0) + 1

        return sorted(freq.keys())
    
    def find_union_set(self,array1:list[int], array2:list[int]) -> list[int]:
        # the | operator performs the union operation
        return sorted(list((set(array1) | set (array2))))
    
    def find_union_optimal(self,array1:list[int], array2:list[int]) -> list[int]:
        i, j = 0, 0
        union = []

        while i < len(array1) and j < len(array2):
            if array1[i] <= array2[j]:
                if not union or union[-1] != array1[i]:
                    union.append(array1[i])
                if array1[i] == array2[j]:
                    j += 1
                i += 1
            else:
                if not union or union[-1] != array2[j]:
                    union.append(array2[j])
                j += 1
        
        while i < len(array1):
            if union[-1] != array1[i]:
                union.append(array1[i])
            i += 1
        
        while j < len(array2):
            if union[-1] != array2[j]:
                union.append(array2[j])
            
            j += 1

        return union
    

"""
11. Intersection of two arrays

"""

class IntersectionArrays:
    def intersection_brute_force(self, array1: list[int], array2: list[int]) -> list[int]:
        intersection = []
        visited = [0] * len(array2)

        for i in range(len(array1)):
            for j in range(len(array2)):
                if array1[i] == array2[j] and visited[j] == 0:
                    intersection.append(array1[i])
                    visited[j] = 1
                    break
                
                
                if array2[j] > array1[i]:
                    break 
        
        return intersection
    
    def intersection_optimal(self, array1:list[int], array2:list[int]) ->list[int]:
        intersection = []

        i,j = 0,0

        while i < len(array1) and j < len(array2):
            if array1[i] < array2[j]:
                i += 1
            elif array2[j] < array1[i]:
                j += 1
            else:
                intersection.append(array1[i])
                i += 1
                j += 1

        return intersection

array1 = [1,2,2,3,3,4,5]
array2 = [2,3,3,6,7,8]

obj = IntersectionArrays()

result = obj.intersection_optimal(array1,array2)
# print("Intersection of two arrays = ",result)


"""
12. Consecutive ones

"""

def consecutive_ones(array:list[int])->int:
    count = 0
    for x in array:
        if x == 1:
            count += 1
        if x == 0:
            count = 0
    return count


"""
13. Given a non-empty array of integers arr, every element appears twice except for one. Find that single one.

"""

class UniqueElement:
    def find_unique_brute_force(self,array:list[int])->int:
        unique_number = -1
        freq={}
        for x in array:
            freq[x] = freq.get(x,0) + 1
        
        print(freq)
        for key, value in freq.items():
            if value == 1:
                unique_number = key
                break
        return unique_number
    
    def find_unique_optimal(self,array:list[int])->int:
        """
        Intuition
        XOR
        A xor A = 0
        A xor 0 = A
        """
        xor = 0

        for arr in array:
            xor = xor ^ arr
        
        return xor
    

array = [1,1,2,3,3,4,4,5,5]

obj = UniqueElement()
print(obj.find_unique_optimal(array))


"""
14. Longest sub-array with sum k
"""


class MaxSubarray:
    def max_sub_array_brute_force(self, array: list[int], k: int) -> int:
        max_length = 0
        n = len(array)

        for i in range(n):
            current_sum = 0
            for j in range(i, n):
                current_sum += array[j]

                if current_sum == k:
                    current_length = j - i + 1
                    if current_length > max_length:
                        max_length = current_length

        return max_length

    def max_sub_array_optimal(self, array: list[int], k: int) -> int:
        """Sliding window approach. Works when array contains non-negative numbers."""
        max_length = 0
        current_sum = 0
        left = 0

        for right in range(len(array)):
            current_sum += array[right]

            while left <= right and current_sum > k:
                current_sum -= array[left]
                left += 1

            if current_sum == k:
                current_length = right - left + 1
                if current_length > max_length:
                    max_length = current_length

        return max_length


def longest_subarray_with_sum_k(array: list[int], k: int) -> int:
    """Universal prefix-sum approach. Works with positives, zeros, and negatives."""
    pre_sum_map: dict[int, int] = {}
    current_sum = 0
    max_len = 0

    for i in range(len(array)):
        current_sum += array[i]

        if current_sum == k:
            if i + 1 > max_len:
                max_len = i + 1

        rem = current_sum - k
        if rem in pre_sum_map:
            length = i - pre_sum_map[rem]
            if length > max_len:
                max_len = length

        # Store only first occurrence of each prefix sum.
        if current_sum not in pre_sum_map:
            pre_sum_map[current_sum] = i

    return max_len


# Example usage:
# mx = MaxSubarray()
# print(mx.max_sub_array_brute_force([1, 2, 1, 1, 1], 3))  # 3
# print(mx.max_sub_array_optimal([1, 2, 1, 1, 1], 3))      # 3
# print(longest_subarray_with_sum_k([2, -1, 2, 3, -2, 1], 3))  # 5


