Here is a simple Python solution using list slicing:

def cyclically_rotate(arr):
    return arr[-1:] + arr[:-1]

def main():
    N = int(input())
    arr = list(map(int, input().split()))
    rotated_arr = cyclically_rotate(arr)
    print(' '.join(map(str, rotated_arr)))

if __name__ == "__main__":
    main()

In this code, `cyclically_rotate` function takes an array as input and returns a new array where the last element is moved to the start of the array. This is done by concatenating the last element (`arr[-1:]`) with the rest of the array (`arr[:-1]`). The `main` function handles the input and output. It reads the number of elements N and the array from the input. It then calls the `cyclically_rotate` function with the input array and prints the result.