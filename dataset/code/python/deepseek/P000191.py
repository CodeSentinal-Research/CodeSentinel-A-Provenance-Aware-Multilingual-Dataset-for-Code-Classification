Here's a simple Python code snippet that uses the built-in `sort()` function of Python's list data type.

def sort_array(array):
    array.sort()
    return array

def main():
    N = int(input())
    array = list(map(int, input().split()))
    sorted_array = sort_array(array)
    print(sorted_array)

if __name__ == "__main__":
    main()

This code first takes the number of elements `N`, then it takes `N` integers from the user, separates them into an array, sorts the array using the `sort()` function of Python's list type, and then prints the sorted array.