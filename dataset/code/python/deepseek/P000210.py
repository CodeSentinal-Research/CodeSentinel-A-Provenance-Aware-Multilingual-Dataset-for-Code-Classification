def find_common_elements():
    size = int(input())
    array1 = list(map(int, input().split()))
    array2 = list(map(int, input().split()))
    array3 = list(map(int, input().split()))

    set1 = set(array1)
    set2 = set(array2)
    set3 = set(array3)

    common = set1.intersection(set2, set3)

    print(*common)

if __name__ == "__main__":
    find_common_elements()