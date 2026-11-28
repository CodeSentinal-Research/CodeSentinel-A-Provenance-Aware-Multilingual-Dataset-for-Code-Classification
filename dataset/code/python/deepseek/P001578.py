Here is the Python code for the problem:

def count_windows():
    N, K = map(int, input().split())
    nums = list(map(int, input().split()))

    count = 0
    for i in range(N - K + 1):
        if len(set(nums[i:i+K])) == K:
            count += 1

    print(count)

count_windows()

This function takes two inputs from the user and processes them. It iterates through the array, and for each subarray, it checks if the length of the set of elements in the subarray (which removes duplicates) is equal to the size of the subarray. If it is, it increments the count. At the end, it prints the count.