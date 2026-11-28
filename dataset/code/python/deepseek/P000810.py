Here is the Python code:

def searchInsert(nums, target):
    if nums[0] > target:
        return 0
    if nums[-1] < target:
        return len(nums)
    for i in range(len(nums)):
        if nums[i] >= target:
            return i

And here is how you can use it:

def main():
    nums = list(map(int, input("Enter the sorted array of integers: ").split()))
    target = int(input("Enter the target integer: "))
    print(searchInsert(nums, target))

if __name__ == "__main__":
    main()

In this program, the user is expected to provide the sorted array of integers and the target integer. The `searchInsert` function will then return the insertion position.