Here is a Python solution for the problem:

def count_subarrays(N, K, A):
    count = 0

    for i in range(N):
        product = 1

        for j in range(i, N):
            product *= A[j]

            if product < K:
                count += 1
            else:
                break

    return count

def main():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    print(count_subarrays(N, K, A))

if __name__ == "__main__":
    main()
This code first reads the number of elements N and K, followed by the array of integers. It then calls the `count_subarrays` function to find and print the count of contiguous subarrays whose product is strictly less than K.

The `count_subarrays` function iterates over the array, and for each element, it calculates the product of all elements in the subarray from the current element to the end. If the product is less than K, it increments the count. If the product is greater than or equal to K, it breaks out of the inner loop. The `main` function handles the input and output, calling `count_subarrays` with the appropriate parameters.