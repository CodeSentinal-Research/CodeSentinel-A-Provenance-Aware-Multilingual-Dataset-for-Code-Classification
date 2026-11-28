Here is the Python code for the problem:

def find_duplicates(n, arr):
    freq = {i: 0 for i in range(1, n+1)}

    for num in arr:
        freq[num] += 1

    duplicates = [num for num, freq in freq.items() if freq > 1]

    return duplicates

n = int(input().strip())
arr = list(map(int, input().strip().split()))
duplicates = find_duplicates(n, arr)
print(' '.join(map(str, duplicates)))

This code first reads the input, then calls the `find_duplicates` function with the input. It prints the duplicate numbers separated by spaces.