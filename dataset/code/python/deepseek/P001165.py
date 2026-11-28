Here is the Python code:

def max_product_subarray(arr):
    max_so_far = arr[0]
    min_so_far = arr[0]
    max_product = arr[0]

    for i in range(1, len(arr)):
        if arr[i] < 0:
            max_so_far, min_so_far = min_so_far, max_so_far

        max_so_far = max(arr[i], max_so_far * arr[i])
        min_so_far = min(arr[i], min_so_far * arr[i])

        max_product = max(max_product, max_so_far)

    return max_product


def main():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(max_product_subarray(arr))


if __name__ == "__main__":
    main()

This code works by maintaining two variables, `max_so_far` and `min_so_far`, to keep track of the maximum and minimum product we've seen so far, respectively. We then iterate through the array and update these variables for each element.

If the current element is negative, we swap `max_so_far` and `min_so_far` because the maximum product of a pair of negative numbers is negative.

Then we update `max_so_far` and `min_so_far` using the current element.

Finally, we update the maximum product if the current element's product is larger.

The time complexity of this code is O(n), where n is the length of the input array, because we only iterate through the array once. The space complexity is O(1), as we only use a constant amount of space.