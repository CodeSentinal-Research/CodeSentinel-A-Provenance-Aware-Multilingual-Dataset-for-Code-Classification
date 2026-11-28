Here is the Python code:

def minOperations():
    n = int(input().strip())
    arr1 = list(map(int, input().strip().split()))
    arr2 = list(map(int, input().strip().split()))

    prefix_sum1 = [0]
    prefix_sum2 = [0]

    for i in range(n):
        prefix_sum1.append(prefix_sum1[-1] + arr1[i])
        prefix_sum2.append(prefix_sum2[-1] + arr2[i])

    minimum_operations = 0

    for i in range(n):
        if prefix_sum1[i] < prefix_sum2[i]:
            minimum_operations += prefix_sum2[i] - prefix_sum1[i]
            arr1[i] += 1

    return minimum_operations

print(minOperations())

In this code, we first read the input and store the prefix sum in two lists. Then, for each element in the first array, we check if it is less than the corresponding element in the second array. If it is, we increment the first array by 1 and add the difference to the total number of operations. The final answer is the total number of operations.