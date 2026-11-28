def tug_of_war():
    n = int(input())
    arr = list(map(int, input().split()))

    arr.sort()

    sum1 = sum(arr[i] for i in range(len(arr) // 2))
    sum2 = sum(arr[~i] for i in range(len(arr) // 2))

    min_diff = sum1 - sum2

    for i in range(len(arr) // 2):
        for j in range(len(arr) // 2, -1, -1):
            if abs(sum1 - sum2 + arr[i] + arr[j]) < min_diff:
                min_diff = abs(sum1 - sum2 + arr[i] + arr[j])
                sum1 -= arr[i]
                sum2 += arr[j]

    print(min_diff)

tug_of_war()

This code first reads the number of elements and the elements themselves from the input. It then sorts the elements in ascending order.

The code then calculates the sum of the two halves of the array and finds the minimum difference.

Then, the code iterates over the pairs of elements in the two halves and updates the sums if the new sum is less than the minimum difference.

The final minimum difference is then printed to the console.