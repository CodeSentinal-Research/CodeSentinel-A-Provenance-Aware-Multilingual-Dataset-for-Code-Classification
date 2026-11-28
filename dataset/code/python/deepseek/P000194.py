Here is the Python code for finding the intersection of two unsorted arrays.

def intersection(arr1, arr2):
    return list(set(arr1) & set(arr2))

def main():
    M, N = map(int, input().split())
    arr1 = list(map(int, input().split()))
    arr2 = list(map(int, input().split()))
    print(intersection(arr1, arr2))

if __name__ == "__main__":
    main()

This code first reads the first line of input which contains the size of the first array (M) and the size of the second array (N). Then it reads the two arrays into the variables `arr1` and `arr2`. Finally, it prints the intersection of the two arrays.