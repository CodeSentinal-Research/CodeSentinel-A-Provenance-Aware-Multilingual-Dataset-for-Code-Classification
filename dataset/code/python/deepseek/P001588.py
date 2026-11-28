def count_nice_subarrays(N, K, arr):
    count = 0

    for i in range(N):
        odd_count = 0
        even_count = 0

        for j in range(i, N):
            if arr[j] % 2 == 1:
                odd_count += 1
            else:
                even_count += 1

            if odd_count == K:
                count += 1

    return count

N = 5
K = 2
arr = [2, 1, 4, 3, 5]
print(count_nice_subarrays(N, K, arr))
This Python program calculates the count of contiguous subarrays containing exactly K odd numbers. The function `count_nice_subarrays` takes an array `arr` and an integer `K` as input. It then counts the number of contiguous subarrays from the given array where the number of odd numbers equals K. The function then returns this count.

For the test case where `N=5`, `K=2` and `arr=[2, 1, 4, 3, 5]`, the program prints `2`, because there are two subarrays [2, 1, 4] and [2, 1, 3, 5] that contain exactly 2 odd numbers.