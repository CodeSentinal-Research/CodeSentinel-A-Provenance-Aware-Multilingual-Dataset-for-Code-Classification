Here is the Python code for the given problem:

def find_parent(arr, i):
    if i == 0:
        return -1
    else:
        return arr[i//2]

def main():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    i = int(input().strip())
    print(find_parent(arr, i))

if __name__ == "__main__":
    main()

In this code, we first define a function `find_parent` that takes a list and an index as input and returns the parent of the node at the given index. The parent of a node at index `i` in the array is found by taking the value at index `i//2`. If the node is at index 0, which is the root, the function returns -1.

In the `main` function, we first read the number of elements `N` and the elements themselves. Then, we read the index of the node whose parent we want to find. Finally, we call `find_parent` and print the result.