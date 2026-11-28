Here is the python code for the problem:

def merge(arr1, arr2):
    arr1.extend(arr2)
    arr1.sort(reverse=True)

    i = len(arr1) - 1
    while i > 0:
        if arr1[i] > arr1[i - 1]:
            arr1[i], arr1[i - 1] = arr1[i - 1], arr1[i]
            i -= 1
        else:
            break

    return arr1

def input_data():
    N = int(input().strip())
    arr1 = list(map(int, input().strip().split()))
    M = int(input().strip())
    arr2 = list(map(int, input().strip().split()))
    return N, arr1, M, arr2

def main():
    N, arr1, M, arr2 = input_data()
    merged = merge(arr1, arr2)
    print(' '.join(map(str, merged)))

if __name__ == "__main__":
    main()

In this code, we first define a function `merge` that merges two arrays into one. We sort both arrays in reverse order (since we need a max heap, we start from the end), then we compare each element with its previous element and swap them if they are not in order.

The function `input_data` is used to handle the input. It reads the number of elements in each array, and the arrays themselves.

Finally, the `main` function is the entry point for the program. It reads the input, merges the arrays, and prints the result.