def findPeakElement(nums):
    if len(nums) == 1:
        return 0
    elif len(nums) == 2:
        return 1 if nums[0] > nums[1] else 0
    else:
        for i in range(len(nums) - 1):
            if nums[i] > nums[i + 1]:
                return i
        return len(nums) - 1

def main():
    n = int(input("Enter the number of elements: "))
    nums = list(map(int, input("Enter the elements: ").split()))
    print(findPeakElement(nums))

if __name__ == "__main__":
    main()

This code first takes the number of elements as an input from the user. Then, it takes the elements as a list of integers. After that, the findPeakElement function is called which finds the peak element in the list. Finally, the main function is called to handle the input and output.