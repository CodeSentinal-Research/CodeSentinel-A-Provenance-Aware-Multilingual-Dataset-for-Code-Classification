Here is the Python code:

def input_data():
    N, K = map(int, input().split())
    arr = list(map(int, input().split()))
    return N, K, arr

def rotate_left(N, K, arr):
    return arr[K:] + arr[:K]

def main():
    N, K, arr = input_data()
    print(rotate_left(N, K, arr))

if __name__ == "__main__":
    main()

This code first defines a function `input_data()` to handle the input. This function reads the number of elements `N` and the number of positions `K`, and the array itself.

Then, it defines a function `rotate_left(N, K, arr)`, which rotates the array to the left by `K` positions. The rotated array is created by concatenating the part of the array from index `K` to the end and the part from the start to `K`.

Finally, the `main()` function calls `input_data()`, `rotate_left(N, K, arr)`, and prints the result.

This code can be run in a Python environment.