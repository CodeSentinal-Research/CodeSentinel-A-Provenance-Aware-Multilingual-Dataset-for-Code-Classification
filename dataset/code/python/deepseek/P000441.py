Here is a simple Python solution for the problem:

def find_max(arr):
    return max(arr)

def main():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(find_max(arr))

if __name__ == "__main__":
    main()

This program works by first reading the size of the array (N), then the actual array of numbers. It then calls the find_max function with the array as its argument and prints the result.

The find_max function uses the built-in max function in Python, which returns the largest item in an iterable or the largest of two or more arguments.