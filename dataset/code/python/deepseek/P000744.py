Here is the Python code for the problem.

def selection_sort(nums):
    if nums:
        smallest = min(nums)
        nums.remove(smallest)
        return [smallest] + selection_sort(nums)
    return []

def main():
    n = int(input("Enter the number of elements in the array: "))
    nums = [int(input("Enter element "+ str(i+1) + ": ")) for i in range(n)]
    print("Sorted array: ", selection_sort(nums))

if __name__ == "__main__":
    main()

This program reads the number of elements (n) and elements of the array from the user. It then calls the `selection_sort` function with the user-provided array as an argument, and prints the sorted array.

Please note that this program uses recursion for the Selection Sort algorithm. The `selection_sort` function repeatedly finds the smallest element from the unsorted part of the array and moves it to the end of the sorted part. The recursion ends when the array becomes empty, at which point the function returns an empty array.