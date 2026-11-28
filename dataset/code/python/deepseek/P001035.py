Here is the Python code for the problem:

def kth_smallest(matrix, k):
    values = [val for sublist in matrix for val in sublist]
    values.sort()
    return values[k-1]

def main():
    n = int(input())
    matrix = []
    for i in range(n):
        matrix.append(list(map(int, input().split())))
    k = int(input())
    print(kth_smallest(matrix, k))

if __name__ == "__main__":
    main()

In this code, the `kth_smallest` function first flattens the given matrix into a list of values. Then it sorts the list of values and returns the kth element. The main function reads the matrix size and values, and then calls the `kth_smallest` function with these values.