Here is a Python code that solves the problem:

def largest_number(arr):
    arr = list(map(str, arr))
    arr.sort(reverse=True)
    return ''.join(arr)

def main():
    n = int(input())
    arr = list(map(int, input().split()))
    print(largest_number(arr))

if __name__ == "__main__":
    main()

In this code, the `largest_number` function first converts the list of integers to a list of strings, so that we can use the `sort` function. Then it sorts the list in reverse order (i.e., from the largest to the smallest), and joins all the elements into a single string. 

The `main` function reads the number of elements, and then reads the elements themselves. It then calls the `largest_number` function to print the largest possible number, and finally prints the result.