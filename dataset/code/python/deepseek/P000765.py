Here's the Python code for the given problem:

def is_max_heap(nums, n):
    for i in range(n):
        if 2 * i + 1 < n:
            if nums[i] < nums[2 * i + 1]:
                return False
        if 2 * i + 2 < n:
            if nums[i] < nums[2 * i + 2]:
                return False
    return True

def main():
    n = int(input("Enter the number of elements: "))
    nums = list(map(int, input("Enter the elements: ").split()))
    if is_max_heap(nums, n):
        print("True")
    else:
        print("False")

if __name__ == "__main__":
    main()

This program will take an input number `n` followed by a space-separated list of integers. The `is_max_heap` function will then check if the list represents a max heap. The `main` function handles the input and output.