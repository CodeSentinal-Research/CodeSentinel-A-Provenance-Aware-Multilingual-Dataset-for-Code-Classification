def union_of_arrays():
    M, N = map(int, input().split())
    array1 = set(map(int, input().split()))
    array2 = set(map(int, input().split()))
    result = array1.union(array2)
    for num in sorted(result):
        print(num)

if __name__ == "__main__":
    union_of_arrays()