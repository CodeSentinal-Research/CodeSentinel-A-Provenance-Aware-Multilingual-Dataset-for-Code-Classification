Here is the python code with the main function and input handling:

def findMin(nums):
    left, right = 0, len(nums) - 1

    while left < right:
        mid = left + (right - left) // 2

        if nums[mid] > nums[right]: 
            left = mid + 1
        else:
            right = mid

    return nums[left]

def main():
    nums = [4,5,6,7,0,1,2]
    print(findMin(nums))

if __name__ == "__main__":
    main()

In the code above, we're using binary search. We start by initializing two pointers, left and right, which represent the start and end of the array. We then enter a while loop until left is less than right. In each iteration of the loop, we calculate the middle index as left + (right - left) // 2. If the middle element is greater than the right element, it means that we're in a part of the left sorted part, so we update our left pointer to mid + 1. Otherwise, we update our right pointer to mid. Finally, once the loop ends, we return the minimum element as the left pointer.