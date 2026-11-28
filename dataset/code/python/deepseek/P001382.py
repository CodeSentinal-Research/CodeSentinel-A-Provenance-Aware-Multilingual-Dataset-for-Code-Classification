Here is the Python code for the problem:

def intersect(N, arr1, M, arr2):
    set1 = set(arr1)
    set2 = set(arr2)
    common = set1 & set2
    sorted_common = sorted(common)
    for element in sorted_common:
        print(element)

def main():
    N, arr1 = map(int, input().split())
    arr1 = list(arr1[:N])
    M, arr2 = map(int, input().split())
    arr2 = list(arr2[:M])
    intersect(N, arr1, M, arr2)

if __name__ == "__main__":
    main()

This program first reads the number of elements in both arrays and the arrays themselves. It then converts the arrays into sets, which are used for fast membership tests. It calculates the intersection of the two sets and sorts the result and prints it.