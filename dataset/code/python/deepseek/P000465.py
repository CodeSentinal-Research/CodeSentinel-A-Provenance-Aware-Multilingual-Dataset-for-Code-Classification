def find_pair(n, diff, arr):
    s = set()
    for i in arr:
        if i in s:
            return 'Yes'
        s.add(i)
    return 'No'

def main():
    n, diff = map(int, input().split())
    arr = list(map(int, input().split()))
    print(find_pair(n, diff, arr))

if __name__ == "__main__":
    main()
This Python program first reads the number of elements `n` and the difference `diff` from the input. It then reads the sorted array `arr`. The function `find_pair` uses a set `s` to store elements of the array. For each element in the array, if the element is in the set, it means that pair with the given difference exists and it returns 'Yes'. If the element is not in the set, it is added to the set. If no pair with the given difference exists, it will return 'No'. The `main` function calls `find_pair` and prints the result.