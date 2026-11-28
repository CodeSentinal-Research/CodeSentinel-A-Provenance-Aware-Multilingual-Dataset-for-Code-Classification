Here is the Python code:

def longest_subarray(N, arr):
    max_len = 0
    ones_count = 0
    ones_index = []

    for i in range(N):
        if arr[i] == 1:
            ones_count += 1
            ones_index.append(i)

    max_len = ones_count

    for i in range(N):
        if arr[i] == 0:
            ones_count = 0
            ones_index = []

            for j in range(i, N):
                if arr[j] == 1:
                    ones_count += 1
                    ones_index.append(j)

                if ones_count + ones_index.index(i) - 1 == j:
                    max_len = max(max_len, ones_count + ones_index.index(i) - 1 - i)

    return max_len


N = int(input().strip())
arr = list(map(int, input().strip().split()))

print(longest_subarray(N, arr))

This code reads the input N and array arr, then calls the function longest_subarray with N and arr as arguments. The function is defined as a function that finds the longest subarray of ones by counting the number of ones and their indices, and then finding the longest subarray that can be formed by deleting one element. The main part of the function is to iterate through the array and keep track of the maximum length of the longest subarray.