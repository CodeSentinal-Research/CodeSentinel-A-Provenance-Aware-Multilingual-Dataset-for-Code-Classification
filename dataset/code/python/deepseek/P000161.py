Here is the Python code to find all unique pairs of elements whose sum equals a given target:

def find_pairs(n, target, arr):
    pairs = []
    visited = set()
    for i in range(n):
        temp = target - arr[i]
        if temp in visited:
            pairs.append((temp, arr[i]))
        visited.add(arr[i])
    return pairs

def main():
    n = int(input().strip())
    target = int(input().strip())
    arr = list(map(int, input().strip().split()))
    pairs = find_pairs(n, target, arr)
    for pair in pairs:
        print(pair)

if __name__ == "__main__":
    main()

This code defines a function `find_pairs(n, target, arr)` that finds all unique pairs of elements whose sum equals the target. It uses a hash set `visited` to track the elements that have been visited. For each element `arr[i]` in the array, it calculates the complement `temp` of the target and checks if `temp` is in `visited`. If it is, it means we have found a pair whose sum equals the target, and we add the pair to the list of pairs. If not, we add `arr[i]` to `visited` and continue with the loop.

The `main()` function reads the number of elements `n`, the target, and the array of integers from the input. It calls `find_pairs(n, target, arr)` to find the pairs and prints them.

Please note that the `main()` function is the entry point of the program and it is called when the script is run.