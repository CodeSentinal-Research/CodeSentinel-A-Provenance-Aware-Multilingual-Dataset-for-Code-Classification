def find_target(target, arr):
    arr.sort()
    try:
        return arr.index(target)
    except ValueError:
        return -1

def main():
    target = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(find_target(target, arr))

if __name__ == "__main__":
    main()
This Python code will handle the search for a target in an infinite sorted array. The program first reads in the target and the array from the input, then calls the `find_target` function to find the target in the array and print the result. The `find_target` function sorts the array, then uses the `index` method to find the target in the sorted array. If the target is not found in the array, `index` will raise a `ValueError`, which is caught and -1 is returned.