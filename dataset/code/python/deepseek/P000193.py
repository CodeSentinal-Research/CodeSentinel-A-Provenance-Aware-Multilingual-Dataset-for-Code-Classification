def read_input():
    M = int(input().strip())
    arr1 = set(map(int, input().strip().split()))
    N = int(input().strip())
    arr2 = set(map(int, input().strip().split()))
    return arr1, arr2

def find_union(arr1, arr2):
    return arr1.union(arr2)

def print_output(result):
    for num in result:
        print(num)

def main():
    arr1, arr2 = read_input()
    result = find_union(arr1, arr2)
    print_output(result)

if __name__ == "__main__":
    main()